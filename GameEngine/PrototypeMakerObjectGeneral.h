/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PrototypeMakerObjectGeneralH
#define PrototypeMakerObjectGeneralH

#include <map>
#include "TypeDef.h"

class IBaseObjectGeneral;

class DllExport PrototypeMakerObjectGeneral
{
  typedef std::map<unsigned int,unsigned int> TMapUintUint;
  TMapUintUint mMapID;

  bool flgNeedInit;
public:
  PrototypeMakerObjectGeneral();
  virtual ~PrototypeMakerObjectGeneral();

  IBaseObjectGeneral* New(unsigned int id_model);

  // ������ ���������� ����������� ������: ��� ������� � ������, �� � ���������� ��� ��,
  // �.�. � ������������ ���������� ��� ������ ����������� ��������� �� ������ ���������� ��� ����������

  // In future must overload
  virtual void Delete(IBaseObjectGeneral* pObject) = 0;// ������ ������� delete pObject;

protected:
  // In future must overload
  virtual IBaseObjectGeneral* NewByID_Behavior(unsigned int id_behavior) = 0;
  unsigned int GetID_ModelByID_Behavior(unsigned int id_model);
  void Init();
};

#endif

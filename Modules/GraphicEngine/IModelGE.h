/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IModelGEH
#define IModelGEH

#include "MathTools.h"

#include <vector>
#include <map>

class TShaderStack;

class DllExport IModelGE
{
public:
  IModelGE();
  virtual ~IModelGE();
  virtual unsigned int GetID() = 0;
  virtual void SetID(unsigned int id) = 0;

  virtual int GetCntEffect() = 0;

  /*
    ������ ����� ������
    � ����������� � ���������� ������
    � ������� �����������
  */
  virtual void Draw(std::vector<void*>* pVecTexCubeMap,//                           
                    std::vector<unsigned char>* state, //                           
                    std::vector<unsigned char>* mask,  //                           
                    std::vector<nsMathTools::TMatrix16*>* matrix,//���-�� ��������� � cSubset 
                    nsMathTools::TMatrix16* pWorld,    // ��� � ��� ���������� ������         
                    float alphaTransparency,  // ������������                       
                    const nsMathTools::TMatrix16* pView, // ������������ � ���������� ������    
                    void* pEffect = NULL) = 0;// �������� �� ������


  virtual void SortPartByAlphabetic() = 0;

  virtual unsigned int GetIndexVisualGroupByName(char* sName, int num) = 0;
  virtual const char* GetNameByIndex(int index) = 0;
  virtual int GetNumUseByIndex(int index) = 0;

  
  virtual void SetShaderStackMask(std::vector<int>* pVectorMask) = 0;// �� ���� ����� ������������� ������� ��������
  virtual TShaderStack* GetShaderStack(int index) = 0;// ����� ���� ��� ���������

	virtual void* MakeTextureForCubeMap(int index) = 0;// ��� ��������� �������� - ���� ��������� ��� �������

};
//-----------------------------------------------------------------



#endif
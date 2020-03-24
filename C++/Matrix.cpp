#include "Matrix.h"
#include <math.h>
namespace Engine
{
	namespace Math
	{
		void Matrix4::SetDiagonal(float i_Val)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					M[i][j] = i == j ? i_Val : 0;
				}
			}
		}
		Matrix4 operator+(const Matrix4& i_Lhs, const Matrix4& i_Rhs)
		{
			Matrix4 result;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					result.M[i][j] = i_Lhs.M[i][j] + i_Rhs.M[i][j];
				}
			}
			return result;
		}
		Matrix4 operator-(const Matrix4& i_Lhs, const Matrix4& i_Rhs)
		{
			Matrix4 result;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					result.M[i][j] = i_Lhs.M[i][j] - i_Rhs.M[i][j];
				}
			}
			return result;
		}
		Matrix4 operator*(const Matrix4& i_Lhs, const Matrix4& i_Rhs)
		{
			Matrix4 result;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					float sum = 0;
					for (int k = 0; k < 4; k++)
					{
						sum += i_Lhs.M[i][k] * i_Rhs.M[k][j];
					}
					result.M[i][j] = sum;
				}
			}
			return result;
		}
		void Matrix4::Transpose()
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					M[i][j] = M[j][i];
				}
			}
		}
		Matrix4 Matrix4::GetTranspose()
		{
			Matrix4 transpose;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					transpose.M[i][j] = M[j][i];
				}
			}
			return transpose;
		}
		void Matrix4::Invert()
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					M[i][j] = M[j][i];
				}
			}
			M[0][3] = -M[0][0] * M[0][3] + -M[0][1] * M[1][3] + -M[0][2] * M[2][3];
			M[1][3] = -M[1][0] * M[0][3] + -M[1][1] * M[1][3] + -M[1][2] * M[2][3];
			M[2][3] = -M[2][0] * M[0][3] + -M[2][1] * M[1][3] + -M[2][2] * M[2][3];
		}
		Matrix4 Matrix4::GetInverse()
		{
			Matrix4 inverse;
			inverse=*this;
			inverse.Invert();
			return inverse;
		}
		//Static
		Matrix4 Matrix4::CreateXRotation(float i_RotationInRadians)
		{
			Matrix4 rotationX;
			rotationX.SetIdentity();
			rotationX.M[1][1] = cos(DegreeToRadians(i_RotationInRadians));
			rotationX.M[1][2] = -sin(DegreeToRadians(i_RotationInRadians));
			rotationX.M[2][1] = sin(DegreeToRadians(i_RotationInRadians));
			rotationX.M[2][2] = cos(DegreeToRadians(i_RotationInRadians));
			return rotationX;
		}
		Matrix4 Matrix4::CreateYRotation(float i_RotationInRadians)
		{
			Matrix4 rotationY;
			rotationY.SetIdentity();
			rotationY.M[0][0] = cos(DegreeToRadians(i_RotationInRadians));
			rotationY.M[0][2] = -sin(DegreeToRadians(i_RotationInRadians));
			rotationY.M[2][0] = sin(DegreeToRadians(i_RotationInRadians));
			rotationY.M[2][2] = cos(DegreeToRadians(i_RotationInRadians));
			return rotationY;
		}
		Matrix4 Matrix4::CreateZRotation(float i_RotationInRadians)
		{
			Matrix4 rotationZ;
			rotationZ.SetIdentity();
			rotationZ.M[0][0] = cos(DegreeToRadians(i_RotationInRadians));
			rotationZ.M[0][1] = -sin(DegreeToRadians(i_RotationInRadians));
			rotationZ.M[1][0] = sin(DegreeToRadians(i_RotationInRadians));
			rotationZ.M[1][1] = cos(DegreeToRadians(i_RotationInRadians));
			return rotationZ;
		}
		Matrix4 Matrix4::CreateTranslation(float i_TransX, float i_TransY, float i_TransZ)
		{
			Matrix4 traslationMatrix;
			traslationMatrix.SetIdentity();
			traslationMatrix.M[0][3] = i_TransX;
			traslationMatrix.M[1][3] = i_TransY;
			traslationMatrix.M[2][3] = i_TransZ;
			return traslationMatrix;
		}
		Matrix4 Matrix4::CreateTranslation(Vector4& i_Translation)
		{
			return CreateTranslation(i_Translation.x(), i_Translation.y(), i_Translation.z());
		}
		Matrix4 Matrix4::CreateScale(float i_ScaleX, float i_ScaleY, float i_ScaleZ)
		{
			Matrix4 scaleMatrix;
			scaleMatrix.SetIdentity();
			scaleMatrix.M[0][0] = i_ScaleX;
			scaleMatrix.M[1][1] = i_ScaleY;
			scaleMatrix.M[2][2] = i_ScaleZ;
			return scaleMatrix;
		}
		
	}
}
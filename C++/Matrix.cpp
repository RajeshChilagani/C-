#include "Matrix.h"
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
			Matrix4 Result;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					Result.M[i][j] = i_Lhs.M[i][j] + i_Rhs.M[i][j];
				}
			}
			return Result;
		}
		Matrix4 operator-(const Matrix4& i_Lhs, const Matrix4& i_Rhs)
		{
			Matrix4 Result;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					Result.M[i][j] = i_Lhs.M[i][j] - i_Rhs.M[i][j];
				}
			}
			return Result;
		}
		Matrix4 operator*(const Matrix4& i_Lhs, const Matrix4& i_Rhs)
		{
			Matrix4 Result;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					float sum = 0;
					for (int k = 0; k < 4; k++)
					{
						sum += i_Lhs.M[i][k] * i_Rhs.M[k][j];
					}
					Result.M[i][j] = sum;
				}
			}
			return Result;
		}
		Matrix4 Matrix4::Transpose(Matrix4& i_Mat)
		{
			Matrix4 Transpose;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					Transpose.M[i][j] = i_Mat.M[j][i];
				}
			}
			return Transpose;
		}
		Matrix4 Matrix4::Transalation(const Vector4& i_Translation)
		{

		}
	}
}
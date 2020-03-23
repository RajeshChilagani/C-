#pragma once
#include "Vector4.h"
namespace Engine
{
	namespace Math
	{
		class Matrix4
		{
		public:
			float M[4][4];
			Matrix4() {}
			Matrix4(const Vector4& InX, const Vector4& InY, const Vector4& InZ, const Vector4& InW);
			void SetDiagonal(float i_Val = 1);
			void SetIdentity();
			//operator
			Matrix4& operator+=(const Matrix4 & i_rhs);
			Matrix4& operator-=(const Matrix4 & i_rhs);
			Matrix4& operator*=(const Matrix4 & i_rhs);
			static Matrix4 Transpose(Matrix4& i_Mat);
			static Matrix4 Transalation(const Vector4& Transalation);
			static Matrix4 Rotation(const Vector4& Transalation);
			static Matrix4 Scale(const Vector4& i_Scale);
		private:

		};
		Matrix4 operator+(const Matrix4& i_Lhs, const Matrix4& i_Rhs);
		Matrix4 operator-(const Matrix4& i_Lhs, const Matrix4& i_Rhs);
		Matrix4 operator*(const Matrix4& i_Lhs, const Matrix4& i_Rhs);
		//Matrix4 operator/(const Matrix4& i_Lhs, const Matrix4& i_Rhs);
	}
}
#include "Matrix_inl.h"
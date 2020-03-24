#pragma once
#include "Vector4.h"
namespace Engine
{
	namespace Math
	{
		inline float DegreeToRadians(float i_Degree)
		{
			float pi = 3.14159265359f;
			return (pi*i_Degree) / 180;
		}
		class Matrix4
		{
		public:
			Matrix4() {}
			Matrix4(const Vector4& InX, const Vector4& InY, const Vector4& InZ, const Vector4& InW);
			void SetDiagonal(float i_Val = 1);
			void SetIdentity();
			void Invert();	
			Matrix4 GetInverse();
			void Transpose();
			Matrix4 GetTranspose();
			//operator
			Matrix4& operator+=(const Matrix4 & i_rhs);
			Matrix4& operator-=(const Matrix4 & i_rhs);
			Matrix4& operator*=(const Matrix4 & i_rhs);
			friend Matrix4 operator+(const Matrix4& i_Lhs, const Matrix4& i_Rhs);
			friend Matrix4 operator-(const Matrix4& i_Lhs, const Matrix4& i_Rhs);
			friend Matrix4 operator*(const Matrix4& i_Lhs, const Matrix4& i_Rhs);
			friend Vector4 operator*(const Matrix4& i_Lhs, const Vector4& i_Rhs);
			friend Vector4 operator*(const Vector4& i_Lhs, const Matrix4& i_Rhs);
			//static
			static Matrix4 CreateIdentity();
			static Matrix4 CreateXRotation(float i_RotationInRadians);
			static Matrix4 CreateYRotation(float i_RotationInRadians);
			static Matrix4 CreateZRotation(float i_RotationInRadians);
			static Matrix4 CreateTranslation(float i_TransX, float i_TransY, float i_TransZ);
			static Matrix4 CreateTranslation(Vector4& i_Trans);
			static Matrix4 CreateScale(float i_ScaleX, float i_ScaleY, float i_ScaleZ);
		private:
			float M[4][4];
		};
		
		
	}
}
#include "Matrix_inl.h"
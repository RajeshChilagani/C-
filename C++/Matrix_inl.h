#pragma once
namespace Engine
{
	namespace Math
	{
		inline void Matrix4::SetIdentity()
		{
			SetDiagonal();
		}
		inline Matrix4::Matrix4(const Vector4& InX, const Vector4& InY, const Vector4& InZ, const Vector4& InW)
		{
			M[0][0] = InX.x(); M[0][1] = InX.y();  M[0][2] = InX.z();  M[0][3] = InX.w();
			M[1][0] = InY.x(); M[1][1] = InY.y();  M[1][2] = InY.z();  M[1][3] = InY.w();
			M[2][0] = InZ.x(); M[2][1] = InZ.y();  M[2][2] = InZ.z();  M[2][3] = InZ.w();
			M[3][0] = InW.x(); M[3][1] = InW.y();  M[3][2] = InW.z();  M[3][3] = InW.w();
		}
		inline Matrix4& Matrix4::operator+=(const Matrix4 & i_Rhs)
		{
			*this = *this + i_Rhs;
			return *this;
		}
		inline Matrix4& Matrix4::operator-=(const Matrix4 & i_Rhs)
		{
			*this = *this - i_Rhs;
			return *this;
		}
		inline Matrix4& Matrix4::operator*=(const Matrix4& i_Rhs)
		{
			*this = *this*i_Rhs;
			return *this;
		}
	}
}

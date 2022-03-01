#pragma once
#ifndef __COMPLEX__
#define __COMPLEX__

class complex
{
public:
	complex(double a = 0, double b = 0) : re(a), img(b) { };//初始化列表
	complex& operator+=(const complex&);
	complex& operator-=(const complex&);
	complex& operator*=(const complex&);
	//complex& operator/=(const complex&);

	
	double getre() const{ return re; };
	double getimg() const { return img; };
private:
	double re, img;
	friend complex& __doapl(complex*, const complex&);
	friend complex& __doami(complex*, const complex&);
	friend complex& __doaml(complex*, const complex&);
	
};

inline complex& __doapl(complex* ths, const complex& r) {
	ths->re += r.re;
	ths->img += r.img;
	return *ths;
}

//inline complex& __doapl(double* ths, const complex& r) {
//	ths += r.re;
//	ths->img += r.img;
//	return *ths;
//}

inline complex& complex::operator+=(const complex& r) {
	return __doapl(this, r);
}

inline complex& __doami(complex* ths, const complex& r) {
	ths->re -= r.re;
	ths->img -= r.img;
	return *ths;
}

inline complex& complex::operator-=(const complex& r) {
	return __doami(this, r);
}

inline complex& __doaml(complex* ths, const complex& r) {
	double f = ths->re * r.re - ths->img * r.img;//为啥新创建个变量
	ths->img = ths->img * r.re + ths->re * r.img;
	ths->re = f;
	return *ths;
}

inline complex& complex::operator*=(const complex& r) {
	return __doaml(this, r);
}

inline double real(const complex& x) {
	return x.getre();
}

inline double img(const complex& x) {
	return x.getimg();
}

inline complex operator+(const complex& x, const complex& y) {
	return complex(real(x) + real(y), img(x) + img(y));
}

inline complex operator+(double& x, const complex& y) {
	return complex(x + real(y), img(y));
}

inline complex operator+(const complex& x, double& y) {
	return complex(real(x) + y, img(x));
}
inline complex operator-(const complex& x, const complex& y) {
	return complex(real(x) - real(y), img(x) - img(y));
}

inline complex operator-(double& x, const complex& y) {
	return complex(x - real(y), img(y));
}

inline complex operator+(const complex& x, double y) {
	return complex(real(x) - y, img(x));
}

inline complex operator*(const complex & x, const complex & y) {
	return complex(real(x) * real(y) - img(x) * img(y), img(x) * real(y) + img(y) * real(x));
}

inline complex operator*(double& x, const complex & y) {
	return complex(x * real(y), x * img(y));
}

inline complex operator*(const complex& x, double& y) {
	return complex(real(x) * y, img(x) * y);
}

inline complex operator/(const complex& x, double y) {
	return complex(real(x) / y, img(x) / y);
}

inline bool operator==(const complex& x, const complex& y) {
	return real(x) == real(y) && img(x) == img(y);
}

inline bool operator==(const complex& x, double y) {
	return real(x) == y && img(x) == 0;
}

inline bool operator==(double x, const complex& y) {
	return real(y) == x && img(y) == 0;
}

inline bool operator!=(const complex& x, const complex& y) {
	return real(x) != real(y) || img(x) != img(y);
}

inline bool operator!=(const complex& x, double y) {
	return real(x) != y || img(x) != 0;
}

inline bool operator!=(double x, const complex& y) {
	return real(y) != x || img(y) != 0;
}

inline complex operator-(const complex& r) {
	return complex(-real(r), -img(r));
}

inline complex operator+(const complex& r) {
	return complex(real(r), img(r));
}
inline complex conj(const complex& x) {
	return complex(real(x), -img(x));
}

inline double norm(const complex& x) {
	return real(x) * real(x) + img(x) * img(x);
}
#include<cmath>
inline complex polar(double x, double t) {
	return complex(x * cos(t), x * sin(t));
}

#endif // !__COMPLEX__



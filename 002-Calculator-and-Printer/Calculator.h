#ifndef __CAL_H_
#define __CAL_H_
class Calculator
{
private:
	int add;
	int sub;
	int mul;
	int div;
public:
	void Init();
	double Add(double a, double b);
	double Sub(double a, double b);
	double Mul(double a, double b);
	double Div(double a, double b);
	void ShowOpCount();
};

#endif

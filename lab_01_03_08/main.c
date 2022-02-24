#include <stdio.h>

float get_normal_mass(float height, float girth)
{
	return height * girth / 240.0f;
}

float get_bml(float mass, float height)
{
	return mass / (height * height * 0.0001f);
}

int main(void)
{
	float h, l, m;
	printf("Input height in cm: ");
	scanf("%f", &h);
	printf("Input chest girth in cm: ");
	scanf("%f", &l);
	printf("Input mass in kg: ");
	scanf("%f", &m);
	
	float m_normal = get_normal_mass(h, l);
	float bmi = get_bml(m, h);

	printf("Normal mass: %f\n", m_normal);
	printf("BMI: %f\n", bmi);
	return 0;
}

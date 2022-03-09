/*
 * task_03.cpp
 *
 *  Created on: 9 мар. 2022 г.
 *      Author: Nikolay Kozlovsky
 */
#include <iostream>

using namespace std;

class Material
{
public:
	virtual float getStress(float strain) = 0;

	virtual ~Material() {}
};


class ElasticMaterial : public Material
{
public:
	ElasticMaterial(float elasticModulus)
{
		this -> elasticModulus = elasticModulus;
}

	float getStress(float strain) override
	{
		return strain * elasticModulus;
	}

private:
	float elasticModulus;
};


class PlasticMaterial : public Material
{
public:
	PlasticMaterial(float elasticModulus, float strainLimit)
{
		this -> elasticModulus = elasticModulus;
		this -> strainLimit = strainLimit;
}

	float getStress(float strain) override
	{
		return elasticModulus * ((strain <= strainLimit)? strain : strainLimit);
	}

private:
	float elasticModulus, strainLimit;
};


/*
int main()
{
	Material* m;
	m = new ElasticMaterial(100);
	cout << "Material stress is: " << m->getStress(0.1) << endl;
	delete m;
	m = new PlasticMaterial(100, 0.01);
	cout << "Material stress is: " << m->getStress(0.1) << endl;
	delete m;

}
 */

/*
	Test output:

	Material stress is: 10
	Material stress is: 1
 */


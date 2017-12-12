//@author Kyle Curry

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void AddIngredients(vector<string>& ingredients)
{
	ingredients.push_back("lettuce");
	ingredients.push_back("tomato");
	ingredients.push_back("mayo");
	ingredients.push_back("bread");
}

void DisplayIngredients(const vector<string>& ingredients)
{
	for (int i = 0; i < 4; i++)
	{
		cout << i << ". " << ingredients[i] << endl;
	}
}

int main()
{
	vector<string> ingredients;
	AddIngredients(ingredients);
	DisplayIngredients(ingredients);


	return 0;
}
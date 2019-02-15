#pragma once

using namespace System::Collections::Generic;

double Pi = 3.1415926535897932384626433832795;
double E  = 2.7182818284590452353602874713527;

List <triangle^>^ to_triangle(List <polygon^>^ pols)
{
	List <triangle^>^ tmp = gcnew List <triangle^>;

	for each (polygon ^ p in pols)
	{
		triangle^ tr = gcnew triangle(p->points[0], p->points[1], p->points[2]);
		tmp->Add(tr);
	}

	return tmp;
}

List <polygon^>^ bisection(List <polygon^>^ pols, double min_length_line)
{
	List <polygon^>^ tmp = gcnew List <polygon^>;

	for each (polygon ^ p in pols)
	{
		tmp->AddRange(p->bisection(min_length_line));
	}

	return tmp;
}

List <line^>^ to_lines(List <polygon^>^ polygons)
{
	List <line^>^ tmp = gcnew List <line^>;

	for each (polygon ^ p in polygons)
	{
		tmp->AddRange(p->list_of_border_lines());
	}

	return tmp;
}

List <point^>^ to_points(List <polygon^>^ polygons)
{
	List <point^>^ tmp = gcnew List <point^>;

	for each (polygon ^ p in polygons)
	{
		tmp->AddRange(p->points);
	}

	return tmp;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

List <polygon^>^ triangulation(List <polygon^>^ pol, double min_length_line)
{
	List <polygon^>^ tmp = gcnew List <polygon^>;
	List <polygon^>^ tmp_1 = gcnew List <polygon^>;
	tmp->AddRange(pol);
	int k;

	do
	{
		k = 0;
		tmp_1->AddRange(bisection(tmp, min_length_line));
		tmp->Clear();
		tmp->AddRange(tmp_1);
		tmp_1->Clear();

		for each (polygon ^ p in tmp)
		{
			if (p->points->Count > 3)
			{
				k++;
			}
		}
	} while (k != 0);

	return tmp;
}


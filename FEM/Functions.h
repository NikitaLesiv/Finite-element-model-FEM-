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

List <polygon ^> ^bisection(List <polygon ^> ^pols, double min_length_line)
{
	List <polygon ^> ^tmp   = gcnew List <polygon ^>;

	for each (polygon ^p in pols)
	{
		tmp->AddRange(p->bisection(min_length_line));
	}

	return tmp;
}

List <polygon ^> ^triangulation(List <polygon ^> ^pol, double min_length_line)
{
	List <polygon ^> ^tmp   = gcnew List <polygon ^>;
	List <polygon ^> ^tmp_2 = gcnew List <polygon ^>;
	List <polygon ^> ^tmp_3 = gcnew List <polygon ^>;

	tmp_2->AddRange(pol);
	
	int k;
	
	do
	{
		k = 0;

		tmp_3->AddRange(bisection(tmp_2, min_length_line));
		tmp_2->Clear();
		tmp_2->AddRange(tmp_3);
		tmp_3->Clear();

		for each (polygon ^ p in tmp_2)
		{
			if (p->points->Count > 3)
			{
				k++;
			}
		}
	} while (k != 0);

	tmp->AddRange(tmp_2);

	return tmp;
}

List <line ^> ^Delaunay_triangulation(List <polygon ^> ^polygons)
{
	List <line ^> ^tmp = gcnew List <line ^>(10);

	return tmp;
}

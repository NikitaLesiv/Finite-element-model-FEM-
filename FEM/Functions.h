#pragma once

using namespace System::Collections::Generic;

double Pi = 3.1415926535897932384626433832795;
double E  = 2.7182818284590452353602874713527;

template <typename T>
List <T> ^array_to_list(array <T> ^arr)
{
	List <T> ^list = gcnew List <T>;

	for each (auto ^i in arr)
	{
		list->Add(i);
	}

	return list;
}

void remove_all(List <polygon ^> ^lists)
{
	for (int i = lists->Count - 1; i >= 0; i--)
	{
		lists->Remove(lists[i]);
		//p->~polygon();
	}
}

List <polygon ^> ^bisection(List <polygon ^> ^pols, double min_length_line)
{
	List <polygon ^> ^tmp = gcnew List <polygon ^>;

	for each (polygon ^p in pols)
	{
		List <polygon ^> ^polygons = p->bisection(min_length_line);

		tmp->AddRange(polygons);
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

		for each (polygon ^p in tmp_2)
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

List <line ^> ^Delaunay_triangulation(array <line ^> ^lines)
{
	List <line ^> ^tmp = gcnew List <line ^>(10);

	return tmp;
}

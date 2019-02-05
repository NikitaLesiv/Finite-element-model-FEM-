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

List <polygon ^> ^triangulation(List <polygon ^> ^polygons, double min_length_line)
{
	List <polygon ^> ^tmp = polygons;
	List <polygon ^> ^tmp_2 = gcnew List <polygon ^>;
	List <polygon ^> ^tmp_3 = gcnew List <polygon ^>;

//	int k;
//	do
//	{
//		k = 0;
	for (int k = 0; k < 6; k++)
	{	
		for (int i = 0; i < tmp->Count; i++) // polygon ^p in tmp
		{
			tmp_2->Clear();
			tmp_2 = tmp[i]->bisection(min_length_line); // AddRange(tmp_1[i]->bisection(min_length_line));
			for each (polygon ^pol in tmp_2) // polygon ^pol in tmp_2
			{
				tmp_3->Add(pol);

				if (pol->points->Count > 3)
				{
				//	k++;///
				}
			}
		}

		tmp->Clear();
		tmp->AddRange(tmp_3);
		tmp_3->Clear();
	}
//	} while (k < 500);

	return tmp;
}

List <line ^> ^Delaunay_triangulation(array <line ^> ^lines)
{
	List <line ^> ^tmp = gcnew List <line ^>(10);

	return tmp;
}

#pragma once

using namespace System::Collections::Generic;

double Pi = 3.1415926535897932384626433832795;
double E  = 2.7182818284590452353602874713527;

void bubble_sort(array <line ^> ^lines)
{
	int N = lines->Length;
	array <line ^> ^tmp = gcnew array <line ^>(N);
	int k;

	do
	{
		k = 0;
		for (int i = 0; i < (N - 1); i++)
		{
			if (lines[i]->length() > lines[i + 1]->length())
			{
				line ^tmp = lines[i + 1];
				lines[i + 1] = lines[i];
				lines[i] = tmp;
				k++;
			}
		}
	} while (k != 0);
}

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

List <line ^> ^Delaunay_triangulation(array <line ^> ^lines)
{
	List <line ^> ^tmp = gcnew List <line ^>(10);

	return tmp;
}

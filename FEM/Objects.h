#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;

///////////////////////////////////////////////////////////////////////////////////

public ref class point
{
public:
	int N = 0; // Номер точки
	int triangleN = 0; // Номер точки
	double x = 0, y = 0;
	bool border = false;
	String ^color = "Black";

	List <Int32>^ Triangles_Numbers = gcnew List <Int32>;

	point() // Конструктор
	{

	}
	point(double x, double y) // Конструктор
	{
		this->x = x;
		this->y = y;
	}
	point(double x, double y, String^ color) // Конструктор
	{
		this->x = x;
		this->y = y;
		this->color = color;
	}

	void show(Graphics^ g, int resolutions_x, int resolutions_y, double scale, int diameter)
	{
		SolidBrush^ brush = gcnew SolidBrush(Color::FromName(color));
		
		int x_px = static_cast <int>(x * resolutions_x / scale - diameter / 2);
		int y_px = static_cast <int>(y * resolutions_y / scale - diameter / 2);

		g->FillEllipse(brush, x_px, y_px, diameter, diameter);
	}

	double distance(point^ p)
	{
		double dist = sqrt(pow(x - p->x, 2) + pow(y - p->y, 2));

		return dist;
	}

	bool equal(point^ p)
	{
		bool condition = (this->x == p->x) && (this->y == p->y); //&& (this->color == p->color);

		return condition;
	}

	point^ operator= (point^ p)
	{
		this->x = p->x;
		this->y = p->y;
		this->color  = p->color;

		return this;
	}

	bool operator== (point^ p)
	{
		bool condition = (this->x == p->x) && (this->y == p->y) && (this->color == p->color);

		return condition;
	}

	~point() // Деструктор
	{

	}
};

public ref class line
{
public:
	int N = 0; // Номер линии
	point ^p_s = gcnew point(0, 0);
	point ^p_f = gcnew point(1, 1);
	String ^color = "Black";
	double k = 1; // Коэффициент наклона отрезка по отношению к оси ОХ (y = kx + b)
	double b = 0; // Смещение отрезка по отношению к оси ОХ (y = kx + b)
	bool border = false;

	line() // Конструктор
	{
	
	}
	line(point ^p_s, point ^p_f) // Конструктор
	{
		this->p_s = p_s;
		this->p_f = p_f;
		b = (p_s->y * p_f->x - p_f->y * p_s->x) / (p_f->x - p_s->x);
		k = (p_f->y - p_s->y) / (p_f->x - p_s->x);
	}
	line(point ^p_s, point ^p_f, String^ color) // Конструктор
	{
		this->p_s = p_s;
		this->p_f = p_f;
		b = (p_s->y * p_f->x - p_f->y * p_s->x) / (p_f->x - p_s->x);
		k = (p_f->y - p_s->y) / (p_f->x - p_s->x);
		this->color = color;
	}

	void show(Graphics ^g, int resolutions_x, int resolutions_y, double scale, float width)
	{
		Pen^ pen = gcnew Pen(Color::FromName(color), width);

		int x_s_px = static_cast <int>(p_s->x * resolutions_x / scale);
		int y_s_px = static_cast <int>(p_s->y * resolutions_y / scale);
		int x_f_px = static_cast <int>(p_f->x * resolutions_x / scale);
		int y_f_px = static_cast <int>(p_f->y * resolutions_y / scale);

		g->DrawLine(pen, x_s_px, y_s_px, x_f_px, y_f_px);
	}

	point ^center()
	{
		point ^tmp = gcnew point();

		tmp->x = (p_s->x + p_f->x) / 2;
		tmp->y = (p_s->y + p_f->y) / 2;

		return tmp;
	}

	double length()
	{
		double tmp = p_s->distance(p_f);

		return tmp;
	}

	void refresh_k_and_b()
	{
		b = (p_s->y * p_f->x - p_f->y * p_s->x) / (p_f->x - p_s->x);
		k = (p_f->y - p_s->y) / (p_f->x - p_s->x);
	}

	point ^intersection_point(line ^l)
	{
		point ^tmp = gcnew point();

		double k1 = k, k2 = l->k;
		double b1 = b, b2 = l->b;

		tmp->x = (b1 - b2) / (k2 - k1);
		tmp->y = k1 * tmp->x + b1;

		return tmp;
	}

	bool intersect(line ^l)
	{
		bool tmp;

		point ^i_p = (gcnew line(p_s, p_f))->intersection_point(l);
		double x1, x2, y1, y2;

		if (p_s->x <= p_f->x)
		{
			x1 = p_s->x;
			x2 = p_f->x;
		}
		else
		{
			x1 = p_f->x;
			x2 = p_s->x;
		}

		if (p_s->y <= p_f->y)
		{
			y1 = p_s->y;
			y2 = p_f->y;
		}
		else
		{
			y1 = p_f->y;
			y2 = p_s->y;
		}

		bool condition = (x1 < i_p->x) && (x2 > i_p->x) && (y1 < i_p->y) && (y2 > i_p->y);

		tmp = condition;

		return tmp;
	}

	line ^operator= (line ^l)
	{
		this->p_s = l->p_s;
		this->p_f = l->p_f;
		this->color = l->color;

		return this;
	}

	~line() // Деструктор
	{

	} 
};

public ref class circle
{
public:
	int N = 0; // Номер окружности
	double x = 0, y = 0; // Координаты центра окружности
	double R = 1; // Радиус окружности
	String ^color = "Black";

	circle() // Конструктор
	{

	}
	circle(double x, double y, double R) // Конструктор
	{
		this->x = x;
		this->y = y;
		this->R = R;
	}
	circle(double x, double y, double R, String ^color) // Конструктор
	{
		this->x = x;
		this->y = y;
		this->R = R;
		this->color = color;
	}
	circle(point^ p, double R) // Конструктор
	{
		this->x = p->x;
		this->y = p->y;
		this->R = R;
	}
	circle(point^ p, double R, String ^color) // Конструктор
	{
		this->x = p->x;
		this->y = p->y;
		this->R = R;
		this->color = color;
	}

	void show(Graphics ^g, int resolutions_x, int resolutions_y, double scale, float width)
	{
		Pen ^pen = gcnew Pen(Color::FromName(color), width);

		int radius_x_px = static_cast <int>(R * resolutions_x / scale);
		int radius_y_px = static_cast <int>(R * resolutions_y / scale);
		int x_px = static_cast <int>(x * resolutions_x / scale) - radius_x_px;
		int y_px = static_cast <int>(y * resolutions_y / scale) - radius_y_px;

		g->DrawEllipse(pen, x_px, y_px, 2 * radius_x_px, 2 * radius_y_px);
	}

	List <point ^> ^intersection_point(line ^l)
	{
		List <point ^> ^points = gcnew List <point ^>;
		double k = l->k, b = l->b;
		double x0 = x, y0 = y;

		double A = pow(k, 2) + 1;
		double B = 2 * k * (b - y0 - (x0 / k));
		double C = pow(b, 2) + pow(y0, 2) - 2 * y0 * b + pow(x0, 2) - pow(R, 2);
		double D = pow(B, 2) - 4 * A * C;

		double x1 = (-B + sqrt(D)) / (2 * A);
		double x2 = (-B - sqrt(D)) / (2 * A);
		double y1 = k * x1 + b;
		double y2 = k * x2 + b;

		points->Add(gcnew point(x1, y1));
		points->Add(gcnew point(x2, y2));
		
		return points;
	}

	bool the_point_enters_the_circle(point^ p)
	{
		if (sqrt(pow(p->x - x, 2) + pow(p->y - y, 2)) <= R)
		{
			return true;
		}
		else
		{
			return false;
		}		
	}

/*
	bool intersect(line^ l)
	{
		bool tmp;
		//point^ i_p = (gcnew line(p_s, p_f))->intersection_point(l);

		bool condition = 1;

		tmp = condition;

		return tmp;
	}
*/

	void operator= (circle ^c)
	{
		this->x = c->x;
		this->y = c->y;
		this->R = c->R;
		this->color = c->color;
	}

	~circle() // Деструктор
	{

	}
};

public ref class triangle
{
public:
	int N = 0; // Номер треугольника
	point ^p_1 = gcnew point(1, 1);
	point ^p_2 = gcnew point(2, 2);
	point ^p_3 = gcnew point(3, 4);
	
	String ^color = "Black";

	triangle() // Конструктор
	{

	}
	triangle(point ^p_1, point ^p_2, point ^p_3) // Конструктор
	{
		this->p_1 = p_1;
		this->p_2 = p_2;
		this->p_3 = p_3;
	}
	triangle(point ^p_1, point ^p_2, point ^p_3, String ^color) // Конструктор
	{
		this->p_1 = p_1;
		this->p_2 = p_2;
		this->p_3 = p_3;
		this->color = color;
	}

	void show(Graphics ^g, int resolutions_x, int resolutions_y, double scale)
	{
		SolidBrush^ brush = gcnew SolidBrush(Color::FromName(color));

		int x_1_px = static_cast <int>(p_1->x * resolutions_x / scale);
		int y_1_px = static_cast <int>(p_1->y * resolutions_y / scale);
		int x_2_px = static_cast <int>(p_2->x * resolutions_x / scale);
		int y_2_px = static_cast <int>(p_2->y * resolutions_y / scale);
		int x_3_px = static_cast <int>(p_3->x * resolutions_x / scale);
		int y_3_px = static_cast <int>(p_3->y * resolutions_y / scale);

		array <Point>^ points = { Point(x_1_px, y_1_px), Point(x_2_px, y_2_px), Point(x_3_px, y_3_px) };

		g->FillPolygon(brush, points);
	}

	circle ^circumscribed_circle()
	{
		circle ^tmp = gcnew circle();

		double x1 = p_1->x, x2 = p_2->x, x3 = p_3->x;
		double y1 = p_1->y, y2 = p_2->y, y3 = p_3->y;
		
		double D = 2 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));

		tmp->x = ((pow(x1, 2) + pow(y1, 2)) * (y2 - y3) + (pow(x2, 2) + pow(y2, 2)) * (y3 - y1) + (pow(x3, 2) + pow(y3, 2)) * (y1 - y2)) / D;
		tmp->y = ((pow(x1, 2) + pow(y1, 2)) * (x3 - x2) + (pow(x2, 2) + pow(y2, 2)) * (x1 - x3) + (pow(x3, 2) + pow(y3, 2)) * (x2 - x1)) / D;
		tmp->R = (gcnew point(tmp->x, tmp->y))->distance(p_2);

		return tmp;
	}

	point^ get_center()
	{
		point^ tmp = gcnew point();

		line^ l1 = gcnew line(p_1, p_2);	
		line^ l2 = gcnew line(p_2, p_3);
		line^ l3 = gcnew line(p_3, p_1);
			
		line^ m1 = gcnew line(p_1, l2->center());
		line^ m2 = gcnew line(p_2, l3->center());
		line^ m3 = gcnew line(p_3, l1->center());
		
		if (m1->intersect(m2) == true)
		{
			tmp = m1->intersection_point(m2);
		}
		else if ((m1->intersect(m2) == false) && (m2->p_s->y != m2->p_f->y))
		{
			tmp = m2->intersection_point(m3);
		}
		else if ((m1->intersect(m2) == false) && (m1->p_s->y != m1->p_f->y))
		{
			tmp = m1->intersection_point(m3);
			
		}

		return tmp;
	}

	List <line^>^ list_of_border_lines()
	{
		List <line^>^ tmp = gcnew List<line^>;
		tmp->Add(gcnew line(p_1, p_2));
		tmp->Add(gcnew line(p_2, p_3));
		tmp->Add(gcnew line(p_3, p_1));
		
		return tmp;
	}

	bool operator== (triangle^ tr)
	{
		bool tmp;

		if ((p_1 == tr->p_1) && (p_2 == tr->p_2) && (p_3 == tr->p_3))
		{
			tmp = true;
		}
		else
		{
			tmp = false;
		}
		return tmp;
	}

	~triangle() // Деструктор
	{

	}
};

/////////////////////////////////////////////////////////////////////////

List <point ^> ^Cyclic_permutation_of_indices(List <point ^> ^list)
{
	int N = list->Count;
	List <point ^> ^tmp = gcnew List <point ^>;
	tmp->Add(list[N - 1]);

	for (int i = 0; i < (N - 1); i++)
	{
		tmp->Add(list[i]);
	}

	return tmp;
}

List <line^>^ remove_copies_from_the_list(List <line^>^ list)
{
	List <line^>^ tmp = gcnew List <line^>;
	List <line^>^ tmp_1 = gcnew List <line^>;

	tmp_1->AddRange(list);
	tmp_1->Sort();

	for each (line ^ l in list)
	{
		int N = tmp_1->Count, k = 0;

		for (int i = 0; i < N; i++)
		{
			if (l == tmp_1[i])
			{
				k++;
			}
		}

		if (k != 0)
		{
			tmp_1->RemoveRange(tmp->IndexOf(l), k);
		}
	}
	tmp->AddRange(tmp_1);

	return tmp;
}

List <point^>^ remove_copies_from_the_list(List <point^>^ list)
{
	List <point^>^ tmp = gcnew List <point^>;
	List <point^>^ tmp_1 = gcnew List <point^>;

	tmp_1->AddRange(list);
	tmp_1->Sort();

	for each (point ^ l in list)
	{
		int N = tmp_1->Count, k = 0;

		for (int i = 0; i < N; i++)
		{
			if (l == tmp_1[i])
			{
				k++;
			}
		}

		if (k != 0)
		{
			tmp_1->RemoveRange(tmp->IndexOf(l), k);
		}
	}
	tmp->AddRange(tmp_1);

	return tmp;
}

List <triangle^>^ remove_copies_from_the_list(List <triangle^>^ list)
{
	List <triangle^>^ tmp = gcnew List <triangle^>;
	tmp->AddRange(list);

	for each (triangle ^ l in list)
	{
		int N = tmp->Count, k = 0;

		for (int i = 0; i < N; i++)
		{
			if (l == tmp[i])
			{
				k++;
			}
		}

		if (k != 0)
		{
			for (int i = 0; i < (k - 1); i++)
			{
				tmp->Remove(l);
			}
		}
	}

	return tmp;
}

//////////////////////////////////////////////////////////////////////////

public ref class polygon
{
public:
	int N = 0; // Номер полигона
	List <point^>^ points = gcnew List<point^>; // Список вершин многоугольника (полигона)
	String^ color = "Black";

	polygon() // Конструктор
	{
	}
	polygon(List<point^>^ points) // Конструктор
	{
		this->points = points;	
	}
	polygon(List <point^>^ points, String^ color) // Конструктор
	{
		this->points = points;
		this->color = color;
	}

	void show(Graphics^ g, int resolutions_x, int resolutions_y, double scale)
	{
		SolidBrush ^brush = gcnew SolidBrush(Color::FromName(color));

		List <Point> ^Points = gcnew List<Point>;

		for (int i = 0; i < points->Count; i++)
		{
			int x_px = static_cast <int>(points[i]->x * resolutions_x / scale);
			int y_px = static_cast <int>(points[i]->y * resolutions_y / scale);

			Points->Add(Point(x_px, y_px));
		}

		g->FillPolygon(brush, Points->ToArray());
	}

	List <line^>^ list_of_border_lines()
	{
		List <line ^> ^tmp = gcnew List<line ^>;

		for (int i = 0; i < points->Count; i++)
		{
			if (i != (points->Count - 1))
			{
				tmp->Add(gcnew line(points[i], points[i + 1], color));
			}
			else
			{
				tmp->Add(gcnew line(points[i], points[0], color));
			}
		}

		return tmp;
	}

	void cyclic_permutation_of_indices()
	{
		int N = points->Count;
		List <point ^> ^tmp = gcnew List <point ^>;

		tmp->Add(points[N - 1]);

		for (int i = 0; i < (N - 1); i++)
		{
			tmp->Add(points[i]);
		}

		points = tmp;
	}

	List <polygon^>^ bisection(double min_length_line)
	{
		List <polygon ^> ^tmp = gcnew List <polygon ^>;

		if (points->Count == 3)
		{
			tmp->Add(gcnew polygon(points));
		}
		else if (points->Count == 40000)
		{	
			line^ l1  = gcnew line(points[0], points[1]);
			line^ l2  = gcnew line(points[1], points[2]);
			line^ l3  = gcnew line(points[2], points[3]);
			line^ l4 =  gcnew line(points[3], points[0]);
			
			line^ l_1 = gcnew line(points[0], points[2]);
			line^ l_2 = gcnew line(points[1], points[3]);
			line^ l   = gcnew line();

			tmp->Add(gcnew polygon());
			tmp->Add(gcnew polygon());

			if ((l1->k == l2->k) || (l3->k == l4->k))
			{
				tmp[0]->points->Add(points[3]);
				tmp[0]->points->Add(points[0]);
				tmp[0]->points->Add(points[1]);

				tmp[1]->points->Add(points[1]);
				tmp[1]->points->Add(points[2]);
				tmp[1]->points->Add(points[3]);

				l = l_2;
			}
			else if ((l1->k == l4->k) || (l3->k == l2->k))
			{
				tmp[0]->points->Add(points[2]);
				tmp[0]->points->Add(points[3]);
				tmp[0]->points->Add(points[0]);

				tmp[1]->points->Add(points[0]);
				tmp[1]->points->Add(points[1]);
				tmp[1]->points->Add(points[2]);

				l = l_1;
			}
			else
			{
				if (l_1->length() <= l_2->length())
				{
					tmp[0]->points->Add(points[2]);
					tmp[0]->points->Add(points[3]);
					tmp[0]->points->Add(points[0]);

					tmp[1]->points->Add(points[0]);
					tmp[1]->points->Add(points[1]);
					tmp[1]->points->Add(points[2]);

					l = l_1;
				}
				else
				{
					tmp[0]->points->Add(points[3]);
					tmp[0]->points->Add(points[0]);
					tmp[0]->points->Add(points[1]);

					tmp[1]->points->Add(points[1]);
					tmp[1]->points->Add(points[2]);
					tmp[1]->points->Add(points[3]);

					l = l_2;
				}
			}
			
			if (l->length() >= min_length_line)
			{
				point ^p = l->center();

				tmp[0]->points->Add(p);
				tmp[1]->points->Add(p);
			}
		}
		else //if (false) // Исправить!!!
		{
			line^ l1 = gcnew line(points[0], points[1]);
			line^ l2 = gcnew line(points[0], points[points->Count / 2]);
			line^ l3 = gcnew line(points[0], points[points->Count - 1]);

			while ((l1->k == l2->k) || (l2->k == l3->k))
			{
				points = Cyclic_permutation_of_indices(points);

				l1 = gcnew line(points[0], points[1]);
				l2 = gcnew line(points[0], points[points->Count / 2]);
				l3 = gcnew line(points[0], points[points->Count - 1]);
			}

			tmp->Add(gcnew polygon());
			tmp->Add(gcnew polygon());

			for (int i = 0; i <= points->Count / 2; i++)
			{
				tmp[0]->points->Add(points[i]);
			}

			for (int i = points->Count / 2; i < points->Count; i++)
			{
				tmp[1]->points->Add(points[i]);
			}

			tmp[1]->points->Add(points[0]);
			
			if (l2->length() >= min_length_line)
			{
				point ^p = l2->center();

				tmp[0]->points->Add(p);
				tmp[1]->points->Add(p);
			}
		}

		return tmp;
	}

	polygon^ operator= (polygon^ p)
	{	
		this->points = p->points;
		this->color = p->color;

		return this;
	}

	bool operator== (polygon^ p)
	{
		bool condition = (points == p->points);

		return condition;
	}

	~polygon() // Деструктор
	{

	}
};

public ref class mesh
{
public:
	List <point^>^ points = gcnew List <point^>;
	List <point^>^ points2 = gcnew List <point^>;
	List <array <Int32>^>^ rules = gcnew List <array <Int32>^>;
	List <String^>^ values = gcnew List <String^>;

	mesh()
	{
		/*
		array <Int32>^ tmpar;
		for (int i=0;i<20;i++) 
		{
			rules->Add(gcnew array <Int32>(3));
		}

		for each (array <Int32>^ tmpar in rules)
		{
			tmpar[0] = 2;
			tmpar[1] = 3;
			tmpar[2] = 5;
		}
		*/
	}

	void show(Graphics^ g, int resolutions_x, int resolutions_y, double scale)
	{


	}


	void remove_copies()
	{
		List <point^>^ tmp_points = gcnew List <point^>;
		int k=0;
		int m;
		tmp_points->Add(points[0]);
		for each (point ^ tpoint in points)
		{
			m = 0;
			for each (point ^ tpoint2 in tmp_points)
			{
				if (tpoint == tpoint2)
				{
					m++;
				}
			}
			if (m == 0)
			{
				tmp_points->Add(tpoint);
			}
		}

		points2 = tmp_points;
	}

	void set(List <triangle^>^ tr)
	{
		List <point^>^ tmp_points = gcnew List <point^>;
		int k = 0;
		for each (triangle ^t in tr)
		{
			t->p_1->Triangles_Numbers->Add(k);
			t->p_2->Triangles_Numbers->Add(k);
			t->p_3->Triangles_Numbers->Add(k);
			tmp_points->Add(t->p_1);
			tmp_points->Add(t->p_2);
			tmp_points->Add(t->p_3);
			k++;
		}

		points = tmp_points;// remove_copies_from_the_list(tmp_points);
		
	}

	void write_rules(List <triangle^>^ tr)
	{
		List <point^>^ tmp_points = gcnew List <point^>;
		int k = 0;
		int count;
		Int32 Nt = Convert::ToInt32(tr->Count);
		String^ tmpstr;
		array <Int32>^ tmpar = gcnew array <Int32>(3);
		count = 0;
		for (Int32 i=0; i < Nt ; i++)
		{
			count = 0;
			tmpstr = "";
			for each (point ^ tpoint in points2)
			{

				for each (Int32^ tl in tpoint->Triangles_Numbers)
				{
					
					if (i == Convert::ToInt32(tl) && count<3)
					{
						tmpstr += Convert::ToString(tl) + " ";
						//tmpar[count] = Convert::ToInt32(tl);
/*						tmpstr += Convert::ToString(tl) + " ";
*/						count++;
					}
				}
			}
			values->Add(tmpstr);
		}
	}


	List <triangle^>^ Delaunay_triangulation()
	{
		List <triangle^>^ tmp = gcnew List <triangle^>;

		return tmp;
	}

	~mesh()
	{

	}
};
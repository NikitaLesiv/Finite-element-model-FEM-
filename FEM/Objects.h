#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;

public ref class point
{
public:
	int N = 0; // ����� �����
	int row; // ����� ������
	int col; // ����� �������
	double x = 0, y = 0;
	bool border = false;
	String ^color = "Black";

	point() // �����������
	{

	}
	point(double x, double y) // �����������
	{
		this->x = x;
		this->y = y;
	}
	point(double x, double y, String ^color) // �����������
	{
		this->x = x;
		this->y = y;
		this->color = color;
	}

	void show(Graphics ^g, int resolutions_x, int resolutions_y, double scale, int diameter)
	{
		SolidBrush^ brush = gcnew SolidBrush(Color::FromName(color));
		
		int x_px = static_cast<int>(x * resolutions_x / scale) - diameter / 2;
		int y_px = static_cast<int>(y * resolutions_y / scale) - diameter / 2;

		g->FillEllipse(brush, x_px, y_px, diameter, diameter);
	}

	double distance(point ^p)
	{
		double dist = sqrt(pow(x - p->x, 2) + pow(y - p->y, 2));

		return dist;
	}

	point^ operator= (point ^p)
	{
		this->x = p->x;
		this->y = p->y;
		this->color  = p->color;

		return this;
	}

	bool operator== (point ^p)
	{
		bool condition = (this->x == p->x) && (this->y == p->y) && (this->color == p->color);

		return condition;
	}

	~point() // ����������
	{

	}
};

public ref class line
{
public:
	int N = 0; // ����� �����
	point ^p_s = gcnew point(0, 0);
	point ^p_f = gcnew point(1, 1);
	String ^color = "Black";
	double k = 1; // ����������� ������� ������� �� ��������� � ��� �� (y = kx + b)
	double b = 0; // �������� ������� �� ��������� � ��� �� (y = kx + b)
	bool border = false;

public:
	line() // �����������
	{
	
	}
	line(point ^p_s, point ^p_f) // �����������
	{
		this->p_s = p_s;
		this->p_f = p_f;
		b = (p_s->y * p_f->x - p_f->y * p_s->x) / (p_f->x - p_s->x);
		k = (p_f->y - p_s->y) / (p_f->x - p_s->x);
	}
	line(point ^p_s, point ^p_f, String^ color) // �����������
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

		int x_s_px = static_cast<int>(p_s->x * resolutions_x / scale);
		int y_s_px = static_cast<int>(p_s->y * resolutions_y / scale);
		int x_f_px = static_cast<int>(p_f->x * resolutions_x / scale);
		int y_f_px = static_cast<int>(p_f->y * resolutions_y / scale);

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

	~line() // ����������
	{

	} 
};

public ref class circle
{
public:
	int N = 0; // ����� ����������
	double x = 0, y = 0; // ���������� ������ ����������
	double R = 1; // ������ ����������
	String ^color = "Black";

	circle() // �����������
	{

	}
	circle(double x, double y, double R) // �����������
	{
		this->x = x;
		this->y = y;
		this->R = R;
	}
	circle(double x, double y, double R, String ^color) // �����������
	{
		this->x = x;
		this->y = y;
		this->R = R;
		this->color = color;
	}
	circle(point^ p, double R) // �����������
	{
		this->x = p->x;
		this->y = p->y;
		this->R = R;
	}
	circle(point^ p, double R, String ^color) // �����������
	{
		this->x = p->x;
		this->y = p->y;
		this->R = R;
		this->color = color;
	}

	void show(Graphics ^g, int resolutions_x, int resolutions_y, double scale, float width)
	{
		Pen ^pen = gcnew Pen(Color::FromName(color), width);

		int radius_x_px = static_cast<int>(R * resolutions_x / scale);
		int radius_y_px = static_cast<int>(R * resolutions_y / scale);
		int x_px = static_cast<int>(x * resolutions_x / scale) - radius_x_px;
		int y_px = static_cast<int>(y * resolutions_y / scale) - radius_y_px;

		g->DrawEllipse(pen, x_px, y_px, 2 * radius_x_px, 2 * radius_y_px);
	}

	array <point ^> ^intersection_point(line ^l)
	{
		array <point ^> ^points = gcnew array <point ^>(2);
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

		points[0] = gcnew point(x1, y1);
		points[1] = gcnew point(x2, y2);
		
		return points;
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

	circle ^operator= (circle ^c)
	{
		circle ^tmp;
		tmp->x = c->x;
		tmp->y = c->y;
		tmp->R = c->R;
		color = c->color;

		return tmp;
	}

	~circle() // ����������
	{

	}
};

public ref class triangle
{
public:
	int N = 0; // ����� ������������
	point ^p_1 = gcnew point(1, 1);
	point ^p_2 = gcnew point(2, 2);
	point ^p_3 = gcnew point(3, 4);
	String ^color = "Black";

	triangle() // �����������
	{

	}
	triangle(point ^p_1, point ^p_2, point ^p_3) // �����������
	{
		this->p_1 = p_1;
		this->p_2 = p_2;
		this->p_3 = p_3;
	}
	triangle(point ^p_1, point ^p_2, point ^p_3, String ^color) // �����������
	{
		this->p_1 = p_1;
		this->p_2 = p_2;
		this->p_3 = p_3;
		this->color = color;
	}

	void show(Graphics ^g, int resolutions_x, int resolutions_y, double scale)
	{
		SolidBrush^ brush = gcnew SolidBrush(Color::FromName(color));

		int x_1_px = static_cast<int>(p_1->x * resolutions_x / scale);
		int y_1_px = static_cast<int>(p_1->y * resolutions_y / scale);
		int x_2_px = static_cast<int>(p_2->x * resolutions_x / scale);
		int y_2_px = static_cast<int>(p_2->y * resolutions_y / scale);
		int x_3_px = static_cast<int>(p_3->x * resolutions_x / scale);
		int y_3_px = static_cast<int>(p_3->y * resolutions_y / scale);

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

	~triangle() // ����������
	{

	}
};

public ref class polygon
{
public:
	int N = 0; // ����� ��������
	List <point ^> ^points = gcnew List<point ^>; // ������ ������ �������������� (��������)
	String ^color = "Black";

	polygon() // �����������
	{
		points->Add(gcnew point(300, 125));
		points->Add(gcnew point(500, 300));
		points->Add(gcnew point(400, 500));
		points->Add(gcnew point(200, 500));
		points->Add(gcnew point(100, 300));
	}
	polygon(List<point ^> ^points) // �����������
	{
		this->points = points;	
	}
	polygon(List <point ^> ^points, String ^color) // �����������
	{
		this->points = points;
		this->color = color;
	}

	void show(Graphics ^g, int resolutions_x, int resolutions_y, double scale)
	{
		SolidBrush ^brush = gcnew SolidBrush(Color::FromName(color));

		List <Point> ^Points = gcnew List<Point>;

		for (int i = 0; i < points->Count; i++)
		{
			int x_px = static_cast<int>(points[i]->x * resolutions_x / scale);
			int y_px = static_cast<int>(points[i]->y * resolutions_y / scale);

			Points->Add(Point(x_px, y_px));
		}

		g->FillPolygon(brush, Points->ToArray());
	}

	List <line ^> ^list_of_border_lines()
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

	void cyclic_permutation_of_indices() // List <point ^> ^list
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

	List <polygon ^> ^bisection(double min_length_line)
	{
		List <polygon ^> ^tmp = gcnew List <polygon ^>;

		if (points->Count == 3)
		{
			tmp->Add(gcnew polygon(points, color));
		}
		else if (points->Count == 4)
		{
			line^ l1 = gcnew line(points[0], points[1], color);
			line^ l2 = gcnew line(points[0], points[2], color);

			if (abs(l1->k) == abs(l2->k))
			{
				do
				{
					cyclic_permutation_of_indices();

					l1 = gcnew line(points[0], points[1], color);
					l2 = gcnew line(points[0], points[2], color);
				} while (abs(l1->k) == abs(l2->k));
			}
			
			line^ l = gcnew line(points[0], points[2], color);

			tmp->Add(gcnew polygon());
			tmp->Add(gcnew polygon());

			tmp[0]->points->Clear();
			tmp[1]->points->Clear();

			tmp[0]->points->Add(points[0]);
			tmp[0]->points->Add(points[1]);
			tmp[0]->points->Add(points[2]);

			tmp[1]->points->Add(points[0]);
			tmp[1]->points->Add(points[3]);
			tmp[1]->points->Add(points[2]);

			if (l->length() >= min_length_line)
			{
				point ^p = l->center();

				tmp[0]->points->Add(p);
				tmp[1]->points->Add(p);
			}
		}
		else
		{
			line^ l1 = gcnew line(points[0], points[1], color);
			line^ l2 = gcnew line(points[0], points[points->Count / 2], color);

			if (abs(l1->k) == abs(l2->k))
			{
				do
				{
					cyclic_permutation_of_indices();

					l1 = gcnew line(points[0], points[1], color);
					l2 = gcnew line(points[0], points[points->Count / 2], color);
				} while (abs(l1->k) == abs(l2->k));
			}

			tmp->Add(gcnew polygon());
			tmp->Add(gcnew polygon());

			tmp[0]->points->Clear();
			tmp[1]->points->Clear();

			tmp[0]->points->Add(points[0]);

			if (l2->length() >= min_length_line)
			{
				point ^p = l2->center();

				tmp[1]->points->Add(p);
			}
			tmp[1]->points->Add(points[points->Count / 2]);

			for (int i = 1; i < points->Count; i++)
			{
				if (i < (points->Count / 2))
				{
					tmp[0]->points->Add(points[i]);
				}
				else
				{
					tmp[1]->points->Add(points[i]);
				}
			}

			tmp[0]->points->Add(points[points->Count / 2]);
			tmp[1]->points->Add(points[0]);

			if (l2->length() >= min_length_line)
			{
				point ^p = l2->center();

				tmp[0]->points->Add(p);
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

	~polygon() // ����������
	{

	}
};

public ref class mesh
{
public:



	mesh()
	{

	}

	~mesh()
	{

	}
};


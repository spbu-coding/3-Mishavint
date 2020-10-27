#include <stdio.h>
#include <math.h>

struct float_point              // Так как у решения уравнения две точки: x1 и x2, будет удобно держать их всегда рядом
{
    float x1;
    float x2;
};

struct double_point            // Тоже самое, но для double
{
    double x1;
    double x2;
};

struct double_point solve_for_doubles(double delta )
{
    struct double_point double_answer;                      // Создали структуру, в которую запишем результаты вычислений, и которую вскоре вернем
    double_answer.x2 = (2.0001 + delta - 2 ) * pow(10 , 4);
    double_answer.x1 = 2.0000 - double_answer.x2;

    return double_answer;
}

struct float_point solve_for_float(float delta )
{
    struct float_point float_answer;                      // Создали структуру, в которую запишем результаты вычислений, и которую вскоре вернем
    float_answer.x2 = (2.0001f + delta - 2 ) * pow(10 , 4);
    float_answer.x1 = 2.0000f - float_answer.x2;

    return float_answer;
}

double distance_between_doubles(struct double_point point1 , struct double_point point2 ) // Возвращаем расстояние между точками на координатной плоскости
{
    return sqrtf((point1.x1 - point2.x1) * (point1.x1 - point2.x1)
                 + (point1.x2 - point2.x2) * (point1.x2 - point2.x2) );
}


float distance_between_floats(struct float_point point1 , struct float_point point2 )  // Возвращаем расстояние между точками на координатной плоскости
{
    return sqrtf((point1.x1 - point2.x1) * (point1.x1 - point2.x1)
                + (point1.x2 - point2.x2) * (point1.x2 - point2.x2) );
}


int main()
{
    float delta_for_float = 0.0000f;
    double delta_for_double = 0.0000;

    printf("delta_for_float = %.20f" , delta_for_float);
    printf("\ndelta_for_double = %.20lf" , delta_for_double);

    struct double_point double_points = solve_for_doubles(delta_for_double) ;
    struct float_point float_points = solve_for_float(delta_for_float) ;

    printf("\n double_point: x1 = %.20lf x2 = %.20lf" , double_points.x1 , double_points.x2);
    printf("\n float_point: x1 = %.20f x2 = %.20f" , float_points.x1 , float_points.x2);



    float distance_between_float_points;
    double distance_between_double_points;


    int i = 1;


    delta_for_float = 0.0001f;
    delta_for_double = 0.0001;
    do
    {
       printf("\n\n ~~~~~~~~~~~~ Experiment [%d] ~~~~~~~~~~~~" , i);
       struct double_point new_double_points = solve_for_doubles((delta_for_double));
       struct float_point new_float_points = solve_for_float(delta_for_float);

       distance_between_double_points = distance_between_doubles(double_points , new_double_points);
       distance_between_float_points = distance_between_floats(float_points , new_float_points);

       printf("\n |delta_for_doubles = %.20lf" , delta_for_double);
       printf("\n |New double points:x1 = %.20lf \n |                  x2 = %.20lf" , new_double_points.x1 , new_double_points.x2);
       printf("\n |distance between double points = %.20lf" , distance_between_double_points);

       printf("\n\n ()delta for floats = %.20f" , delta_for_float);
       printf("\n ()new float points: x1 = %.20f \n ()                  x2 = %.20f" , new_float_points.x1 , new_float_points.x2);
       printf("\n ()distance between float points = %.20f" , distance_between_float_points);
       
        delta_for_double /= 2.000;
        delta_for_float /= 2.000f;
       ++i;
    } while ((distance_between_double_points != 0) || (distance_between_float_points > 0.000001f));


}

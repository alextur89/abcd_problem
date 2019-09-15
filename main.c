#include <stdio.h>
#include <stdlib.h>

#define parabola(c, the_value)                                                 \
  ((-1) * c * c + (the_value - 2) * c + (the_value - 2))

int abcd_solve(int the_value) {
  int ret = 0;
  /* Теория: Решение геометрическое. ab + bc + cd - как сумма площадей
   * подквадратов.
   *
   * Приведем исходные ab + bc + cd (путем прибавления и вычитания da)
   * к виду ab + bc + cd + da – da = b(a + c) + d(c + a) – da = (b + d)(a + c) –
   * da Теперь перенеся это выражение в геометрическую форму представим квадрат,
   * одна сторона которого = a + c, другая = b + d:
   *
   *      |''''''''''''
   *    c |*bc| *cd   |
   *      |___|_______|
   *    a |*ab|  ad   |
   *      |___________|
   *        b     d
   * Мы будем максимизировать области отмеченные *. Очевидно, что требуемые
   * области по площади больше тогда, когда a принимает минимальное значение = 1
   * (чтобы минимизировать квадрат ad). Точно из тех же соображений требуется
   * брать за d тоже минимальное значение, d = 1. Переписав исходное выражение,
   * получим: a + b + c + d = the_value 1 + b + c + 1 = the_value b + c =
   * the_value b = the_value – c
   *
   * Максимизируем: max (b + 1)(1 + c) – 1 = max (the_value - 1 – c)(1 + c) – 1
   * = max –c^2 + (the_value - 2)c + (the_value - 2) Получившаяся парабола имеет
   * экстремум в точке максимума (тк коэффициент перед c отрицательный). Решая
   * простейшее квадратное уравнение получим c при котором a + b + c + d
   * максимальна. Из известного c получим d. a и d мы получили ранее.
   */
  double x = (-1) * (the_value - 2) / 2.0 *
             (-1); //точка экстремума, число может быть с плавающей точкой
                   //поэтому следует рассмотреть ближайщие целые
  int x_floor = (int)x; //пол
  int x_ceil = x_floor; //потолок
  if ((x - x_floor) > 0) {
    x_ceil = x_floor + 1;
  } else if ((x - x_floor) < 0) {
    x_ceil = x_floor - 1;
  }
  //для пола и потолка ищем максимальное значение
  int r1 = parabola(x_floor, the_value);
  int r2 = parabola(x_ceil, the_value);
  if (r1 >= r2) {
    ret = r1;
  } else {
    ret = r2;
  }
  return ret;
}

int main(int argc, const char *argv[]) {
  if (argc > 1) {
    int param = 0;
    param = atoi(argv[1]);
    if (param < 4 || param > 1000) {
      printf("warning, wrong input! value must be in [4,1000]\n");
      exit(-1);
    }
    int result = abcd_solve(param);
    printf("%i\n", result);

  } else {
    printf("wrong list of arguments. you must give integer value for calc!");
  }
  return 0;
}

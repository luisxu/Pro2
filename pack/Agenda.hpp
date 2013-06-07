#ifndef AGENDA_HPP
#define AGENDA_HPP

#include "Historico.hpp"
#include <vector>

class Agenda {

private:

// podéis mantener, modificar o prescindir de los campos y de las
// operaciones privadas incluidos en esta propuesta de "private" e
// incluso anadir otros distintos; en el caso de las operaciones privadas
// es necesario proporcionar la especificación pre/post


    int id_app;   // identificador de la cita

  int N;   // número de funcionarios de la administración
  int D;   // número de días futuros relevantes para la agenda;
  int id_primera_cita_libre; // mínimo entero positivo que no se ha
                             // utilizado aún como identificador de una cita
  int dia_act; // dia actual de la agenda

  /* Citas de los dias relevantes para la agenda: almacena las citas de D+1
     días relevantes: un dia "actual" y D futuros */
  vector<vector<int> > agenda; 
  /* todos los valores de agenda son >=0; el valor 0 indica día libre,
     en caso contrario, indica día ocupado por una cita de id igual al valor */

public:

// no podéis cambiar las cabeceras ni las especificaciones de las
// operaciones públicas

  Agenda(int n, int d);
  /* Pre: n > 0, d > 0 */
  /* Post: crea una agenda sin citas y sin días inhábiles, con capacidad para
     almacenar citas de n funcionarios y d+1 días */
 
  void avanzar_dia(Historico& hist, int dia_reg);
  /* Pre: dia_reg >= ACT, con ACT = consultar_dia_act(), todas las citas de
     hist son más antiguas que ACT */
  /* Post: si dia_reg > ACT:
       a) han pasado a hist las citas del p.i. realizadas los días 
          del intervalo [ACT, dia_reg-1] que no sean más antiguas 
          que dia_reg-K, donde K = hist.num_dias_hist();
       b) se han borrado de hist y del p.i. las citas realizadas los días
          anteriores a dia_reg-K; 
       c) se han habilitado (sin citas) los días del p.i. comprendidos en el 
          intervalo [ACT + D + 1, dia_reg + D] donde D = consultar_num_dias();
       d) el día actual del p.i. pasa a ser dia_reg */

  void anadir_cita(int func, int dia); 
  /* Pre: 0 < func <= consultar_num_funcionarios(), ACT < dia <= ACT+D,
     donde ACT = consultar_dia_act() y D = consultar_num_dias() */ 
  /* Post: el funcionario func del p.i. pasa a tener una cita el día "dia"
     con un identificador nuevo */

  void consultar_cita(int func, int dia, int& id_cita) const;
  /* Pre: 0 < func <= consultar_num_funcionarios(), ACT < dia <= ACT+D,
     donde ACT = consultar_dia_act() y D = consultar_num_dias() */
  /* Post: si el día "dia" hay alguna cita programada para el funcionario
     func, id_cita contiene el identificador de la cita programada; en
     otro caso, id_cita es igual a 0 */
  
  int consultar_dia_act() const;
  /* Pre: cierto */
  /* Post: devuelve el día actual del parámetro implícito */

  int consultar_num_dias() const;
  /* Pre: cierto */
  /* Post: devuelve el número de días futuros relevantes del parámetro
     implícito */

  int consultar_num_funcionarios() const;
  /* Pre: cierto */
  /* Post: devuelve el número de funcionarios del parámetro implícito */
  
  void escribir_citas_vivas() const; 
  /* Pre: cierto */
  /* Post: escribe la información que contiene el p.i. sobre las citas
     programadas para los D dias posteriores a su dia actual,
     donde D = consultar_num_dias() */

};

#endif

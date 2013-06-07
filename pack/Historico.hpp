#ifndef HISTORICO_HPP
#define HISTORICO_HPP

#include "utils.PRO2"
#include <list>

class Historico {

  /* Conjunto de citas ordenadas cronológicamente por día, y crecientemente
  por identificador de funcionario para las citas realizadas un mismo día. La
  diferencia entre el día de la cita más antigua y el día de la cita más
  nueva no puede ser mayor que K-1 */

private:

  /* Estructura con la información relevante de una cita realizada */
  struct Cita {
    int id; // identificador de la cita
    int f;  // identificador del funcionario que atendió la cita
    int d;  // día en el que se realizó la cita
  };

  /* Número de días relevantes para el Historico */
  int K;

  /* Lista de citas */
  list<Cita> historico;


public:

  Historico(int k);
  /* Pre: k > 0 */
  /* Post: crea un objeto de tipo Historico que puede almacenar información
  sobre las citas realizadas durante k días */

  void anadir_cita(int id_cita, int id_f, int dia_cita);
  /* Pre: id_cita > 0, id_f > 0, dia_cita > 0; la cita definida por dia_cita e
  id_f es posterior a todas las del parámetro implícito */
  /* Post: se ha añadido al p.i. la cita cuyos datos son (dia_cita, id_f,
  id_cita) */

  void limpiar_obsoletas(int d); 
  /* Pre: d > 1 */
  /* Post: se han eliminado del p.i. las citas cuyos días de realización
  son menores que el día d-K, con K = num_dias_hist() */

  int num_dias_hist() const;
  /* Pre: cierto */
  /* Post: devuelve el número de días relevantes del parámetro implícito */

  void escribir_historico(int d) const;
  /* Pre: cierto */
  /* Post: se ha escrito por el canal de salida estandar la información sobre
  las citas realizadas los n días anteriores a d, donde n = min(d-1, K),
  siendo K = num_dias_hist().  Las citas realizadas se escriben ordenadas
  cronológicamente por día, y crecientemente por identificador de funcionario
  para las citas realizadas un mismo día */
};

#endif


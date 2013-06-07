#ifndef ORGANIGRAMA_HPP
#define ORGANIGRAMA_HPP

#include "Agenda.hpp"
#include "Arbre.hpp"

class Organigrama{

private:

// podéis mantener, modificar o prescindir de los campos y de las
// operaciones privadas incluidos en esta propuesta de "private" e
// incluso añadir otros distintos; en el caso de las operaciones privadas
// es necesario proporcionar la especificacion pre/post


  /* Arbol de enteros que contiene los identificadores de los funcionarios
     según su organigrama */
  Arbre<int> a;

  static void leer_arbol(Arbre<int> &a, int marca);
  /* Pre: el canal estándar de entrada contiene un árbol de enteros en
     preorden con la marca 'marca' */
  /* Post: a contiene el árbol de enteros leído del canal estándar de
     entrada */


  int assign_offi_less_level(Arbre<int>& a, Agenda& agenda, int day, int& level_aux, int level, bool& found, int& depth);
  // completar con las cabeceras del resto de operaciones privadas de la clase


public:

// no podeis cambiar las cabeceras ni las especificaciones de las
// operaciones publicas

  Organigrama();
  /* Pre: cierto */
  /* Post: el parámetro implícito es un organigrama vacío */
  
  void pedir_cita2(Agenda& ag, int niv);
  /* Pre: niv >= 0 */
  /* Post: si la cita es concertable con los datos de ag y el parámetro
     implícito en un dia posterior a ag.consultar_dia_act(), con un nivel de
     funcionario menor o igual que niv, se ha modificado ag como resultado
     de la petición de una cita con modelo por nivel niv */
 
  void leer_organigrama();
  /* Pre: el canal estándar de entrada contiene un organigrama */
  /* Post: el parámetro implícito contiene el organigrama leído del canal
     estándar de entrada */
  
};

#endif


#include "Historico.hpp"
#include "Agenda.hpp"
#include "Organigrama.hpp"

int main() {

  int N = readint();
  int D = readint();
  int K = readint();
 
  Agenda ag(N,D);
  Historico hist(K);

  Organigrama org;
  org.leer_organigrama();

  int op = readint();
  while (op!=-5){
    int dia_reg = readint();
    ag.avanzar_dia(hist, dia_reg);
    // en este punto, el día actual de ag es dia_reg
    // y no hace falta pasarlo como parametro a las ops de Agenda
    if (op==-1) {
       int nivel = readint();
       org.pedir_cita2(ag, nivel);
    }
    else if  (op==-3) {
      hist.escribir_historico(dia_reg);
    }
    else if  (op==-4) {
      ag.escribir_citas_vivas();
    }
    op = readint();
  }
}


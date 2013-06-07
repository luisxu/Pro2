#include "Historico.hpp"


Historico::Historico(int k) {
  K = k;
}


int Historico::num_dias_hist() const {
  return K;
}

void Historico::anadir_cita(int id_cita, int id_f, int dia_cita) {
  Cita c = {id_cita,id_f,dia_cita};
  historico.insert(historico.end(),c);
}


void Historico::escribir_historico(int dr) const {
  int primer_dia = dr - K; 
  if (primer_dia < 1) primer_dia = 1; 
  cout << "Citas ya realizadas: el intervalo relevante de dias es " << 
  primer_dia << ' ' << dr - 1 << endl;
  list<Cita>::const_iterator it;
  for (it = historico.begin(); it != historico.end(); ++it) {
      cout << it->d << " " << it->f << " " << 
        it->id << endl;
  }
  cout << endl;
}


void Historico::limpiar_obsoletas(int d) {
  int primer_dia = d - K; 
  list<Cita>::iterator it = historico.begin();
  while (it != historico.end() and it->d < primer_dia) {
    it = historico.erase(it);
  }
}

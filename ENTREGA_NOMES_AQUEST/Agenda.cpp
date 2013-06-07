#include "Agenda.hpp"

// podéis mantener, modificar o prescindir del código incluido en esta
// propuesta de implementación, pero debeis mantener las cabeceras y
// las especificaciones de las operaciones públicas

Agenda::Agenda(int n, int d) {
  N = n;
  D = d;
  id_primera_cita_libre = 1;
  dia_act = 1;
  agenda = vector<vector<int> >(d+1,vector<int>(n,0)); 
  id_app = id_primera_cita_libre;
}


void Agenda::avanzar_dia(Historico& hist, int dia_reg) {
    if (dia_act < dia_reg){
    //cout << "el dia actual es " << dia_act << endl;
    //cout << "el dia de registro es " << dia_reg << endl;
    // se recorren los días que se quitan del p.i    
    for(int d=dia_act; d<dia_reg; ++d){ 
      // se recorren los funcionarios de dichos días
       for(int f=0; f<N; ++f){
           int id_cita = agenda[d%(D+1)][f];
           int copy = id_cita;
           agenda[d%(D+1)][f] = 0;   // inhabilitar
           if (copy > 0) hist.anadir_cita(copy, f+1, d);
            hist.limpiar_obsoletas(dia_reg);
        }
     }

  }
   // actualizar dia_act
   dia_act = dia_reg;
}

// si es necesario, habilitar los nuevos días
// ...

// borrar de hist las citas demasiado antiguas

void Agenda::anadir_cita(int func, int dia) {
    if (id_primera_cita_libre == 1) {
        agenda[dia%(D+1)][func-1] = id_primera_cita_libre;
        ++id_primera_cita_libre;
    }
    else {
        ++id_app;
        agenda[dia%(D+1)][func-1] = id_app;
    }
}


void Agenda::consultar_cita(int func, int dia, int& id_cita) const {
    if (agenda[dia%(D+1)][func-1] != 0) {
        id_cita = id_app;
    }
    else id_cita = 0;
}


int Agenda::consultar_dia_act() const {
  return dia_act;
}

int Agenda::consultar_num_dias() const {
  return D;
}

int Agenda::consultar_num_funcionarios() const {
  return N;
}

void Agenda::escribir_citas_vivas() const {
  cout << "Citas vivas: el intervalo relevante de dias es " << 1 + dia_act << ' ' << D + dia_act << endl;
  for (int i = dia_act+1; i <= dia_act+D; ++i) {
      for (int j = 1; j <= N; ++j) {
          int id_cita = agenda[i%(D+1)][j-1];
          if (id_cita != 0) {
              cout << i << " " << j << " " << id_cita << endl;
          }
      }
  }
  cout << endl;
}

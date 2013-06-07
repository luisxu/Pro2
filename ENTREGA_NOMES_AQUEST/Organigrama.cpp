#include "Organigrama.hpp"

// podéis mantener, modificar o prescindir del código incluido en esta
// propuesta de implementación, pero debéis mantener las cabeceras y
// las especificaciones las operaciones públicas


Organigrama::Organigrama() {

}

void Organigrama::pedir_cita2(Agenda& ag, int nivel) {
    int level_aux = 0;
    int id_offi;
    bool found;
    int depth;
    int day = ag.consultar_dia_act()+1;
    bool end = false;
    int num_day = ag.consultar_num_dias();
    int limit_day = day+ num_day;

    while (not end and day < limit_day) {
        id_offi = assign_offi_less_level(a, ag, day, level_aux, nivel, found, depth);
        if (found) end = true;
        else ++day;
    }
    if (end) ag.anadir_cita(id_offi, day);
}

void Organigrama::leer_organigrama() {
  leer_arbol(a,0);
}

void Organigrama::leer_arbol(Arbre<int> &a, int marca) {
  int r; 
  cin >> r; 
  if (r != marca) {
      Arbre<int> hi, hd; 
      leer_arbol(hi,marca);
      leer_arbol(hd,marca);
      a.plantar(r,hi,hd);
  }
}

// completar con el resto de las operaciones privadas de la clase

int Organigrama::assign_offi_less_level(Arbre<int> &a, Agenda &agenda, int day, int& level_aux, int level, bool &found, int& depth)
{
    int id;
    if (level_aux <= level and not a.es_buit()) {
        int root = a.arrel();
        int id_cita;
        agenda.consultar_cita(root, day, id_cita);
        if (id_cita == 0) {
            found = true;
            depth = 0;
            id = root;
        }
        else {
            ++level_aux;
            Arbre<int> a1, a2;
            a.fills(a1, a2);
            int depth1, depth2;
            bool found1, found2;
            int id_1, id_2;
            id_1 = assign_offi_less_level(a1, agenda, day, level_aux, level, found1, depth1);
            id_2 = assign_offi_less_level(a2, agenda, day, level_aux, level, found2, depth2);

            if (found1 and found2) {
                depth1 = depth1 + 1;
                depth2 = depth2 + 1;
                if (depth1 <= depth2) {
                    depth = depth1;
                    id = id_1;
                }
                else {
                    depth = depth2;
                    id = id_2;
                }
            }

            else if (found1) {
                depth = depth1 + 1;
                id = id_1;
            }
            else if (found2) {
                depth = depth2 + 1;
                id = id_2;
            }
            found = found1 or found2;
            --level_aux;
            a.plantar(root, a1, a2);
        }
    }
    else found = false;
    if (found) return id;
    else return -1;
}


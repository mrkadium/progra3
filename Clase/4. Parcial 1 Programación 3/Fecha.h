#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
    private:
        string dia;
        string mes;
        string anio;
    public:
        Fecha(){
        }
        Fecha(string d, string m, string a){
            this->dia = d;
            this->mes = m;
            this->anio = a;
        }
        void setFecha(int d, int m, int a){
            this->dia = d;
            this->mes = m;
            this->anio = a;
        }
        string getFecha(){
            return this->dia + "/" + this->mes + "/" + this->anio;
        }

#endif // FECHA_H_INCLUDED

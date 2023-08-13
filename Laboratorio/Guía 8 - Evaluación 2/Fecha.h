#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
private:
    int Dia;
    int Mes;
    int Anio;
    Fecha *fech;
public:
    Fecha(){
    }
    Fecha(int d, int m, int a){
        this->Dia = d;
        this->Mes = m;
        this->Anio = a;
    }
    Fecha *CalculoFecha(Fecha *fp, int d){
        //calcular fecha de devolución, sumándole al día de la fecha de préstamos el número de días de préstamo
        //si es mes de 30 y se pasa de 30, sumarle la diferencia a dias y sumarle 1 a mes
        Fecha *fdev;
        int diad, mesd;
        int aniod = fp->getAnio();

        ///MESES DE 30 DIAS (ABRIL, JUNIO, SEPTIEMBRE, NOVIEMBRE)
        if(fp->getMes() == 4 || fp->getMes() == 6 || fp->getMes() == 9 || fp->getMes() == 11){ //(fp->getMes() == 4 && (d + fp->getDia()) > 30)
            if((fp->getDia() + d) > 30){ // si se pasa del 30
                mesd = fp->getMes() + 1; //un mes mas
                diad = ((fp->getDia() + d) - 30); //dia = la suma de el dia de la fecha mas los dias de prestamo menos 30, para que me de los dias que se pasa del mes
            }else{ //si no se pasa del mes
                mesd = fp->getMes(); //el mes será el mismo
                diad = fp->getDia() + d; //sólo se sumarán los días
            }
        }else{
            ///FEBRERO
            if(fp->getMes() == 2){
                ///BISIESTO
                if ((fp->getAnio()%4 == 0 && fp->getAnio()%100 != 0) || (fp->getAnio()%4 == 0 && fp->getAnio()%400 == 0)){
                    if((fp->getDia() + d) > 29){
                        mesd = fp->getMes() + 1;
                        diad = (fp->getDia() + d) - 29;
                    }else{
                        mesd = fp->getMes();
                        diad = fp->getDia() + d;
                    }
                }else{
                    if((fp->getDia() + d) > 28){
                        mesd = fp->getMes() + 1;
                        diad = (fp->getDia() + d) - 28;
                    }else{
                        mesd = fp->getMes();
                        diad = fp->getDia() + d;
                    }
                }
            }else{
                ///MESES DE 31 DIAS (ENERRO, MARZO, MAYO, JULIO, AGOSTO, OCTUBRE, DICIEMBRE)
                if((fp->getDia() + d) > 31){
                    if(fp->getAnio() == 12){ ///SI ES DICIEMBRE, Y SE PASA DEL MES
                        aniod = fp->getAnio() + 1;
                        mesd = 1;
                        diad = (fp->getDia() + d) - 31;
                    }else{
                        mesd = fp->getMes() + 1;
                        diad = (fp->getDia() + d) - 31;
                    }
                }else{
                    mesd = fp->getMes();
                    diad = fp->getDia() + d;
                }
            }
        }
        fdev = new Fecha(diad, mesd, aniod);
        return fdev;
    }
    Fecha *getFecha(){
        return this->fech;
    }
    int getDia(){
        return this->Dia;
    }
    int getMes(){
        return this->Mes;
    }
    int getAnio(){
        return this->Anio;
    }
    void setFecha(Fecha *f){
        this->fech = f;
    }
    bool esValida(){
        bool valida = false;
        if (this->Mes == 4 || this->Mes == 6 || this->Mes == 9 || this->Mes == 11){
            if (this->Dia > 0 && this->Dia <=30){
                valida = true;
            }
        }
        else{
            if (this->Mes == 2){
                ///Es bisiesto
                if ((this->Anio%4==0 && this->Anio%100!=0)||(this->Anio%4==0 && this->Anio%400==0)){
                    if (this->Dia >0 && this->Dia <=29){
                        valida = true;
                    }
                }
                else{
                    if (this->Dia > 0 && this->Dia <=28){
                        valida = true;
                    }
                }
            }
            else{
                ///Los meses de 31
                if (this->Mes >0 && this->Mes <=12){
                    if (this->Dia > 0 && this->Dia <=31){
                        valida = true;
                    }
                }
            }
        }
        return valida;
    }

};

#endif // FECHA_H_INCLUDED

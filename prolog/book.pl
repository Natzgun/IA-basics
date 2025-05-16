encima(x,y).
encima(x,z).

arriba(x,y) :- encima(x,y).

soporta(y, x) :- encima(x,y).

encima(x,y) :- soporta(y,x).

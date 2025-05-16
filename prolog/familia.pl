varon(francisco).
varon(mario).
varon(eduardo).
varon(luis).

mujer(victoria).
mujer(alicia).
mujer(beatriz).
mujer(veronica).

padres(eduardo,francisco,victoria).
padres(alicia,francisco,victoria).
padres(luis,eduardo,veronica).
padres(beatriz,mario,alicia).

abuelo(francisco).
abuela(victoria).

esposos(eduardo, vernonica).
esposos(mario, alicia).
esposos(francisco, victoria).

hermano(El, X) :- varon(El), padres(El, M, P), padres(X, M, P).
hermana(Ella, X) :- mujer(Ella), padres(Ella, M, P), padres(X, M, P).

hijo(El, X) :- varon(El), padres(El, X, _).
hijo(El, X) :- varon(El), padres(El, _, X).

hija(Ella, X) :- mujer(Ella), padres(Ella, X, _).
hija(Ella, X) :- mujer(Ella), padres(Ella, _, X).

nieto(El, X) :- varon(El), padres(El, Y, _), padres(Y, X, _).






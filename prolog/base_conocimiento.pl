happy(yolanda).

listens2Music(mia).
listens2Music(yolanda) :- happy(yolanda).

playsAirGuitar(mia) :- listens2Music(mia).
playsAirGuitar(yudy) :- listens2Music(yudy).

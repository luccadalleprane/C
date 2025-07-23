clc;
clear;

syms t s

x = -1.25 + 3.5*t*exp(-2*t) + 1.25*exp(-2*t);

% Transformada de Laplace
X = laplace(x, t, s);

% Exibir a Transformada de forma bonita
disp('Transformada de Laplace:');
pretty(X)
pretty(vpa(X, 4))

% Transformada Inversa para verificar
x_inv = ilaplace(X, s, t);

% Exibir a Transformada Inversa
disp('Transformada Inversa :');
pretty(x_inv)
pretty(vpa(x_inv, 4))

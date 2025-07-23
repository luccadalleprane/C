clc;
clear;

syms Y s t

% Condições iniciais
y0 = 1;
dy0 = 3;

% Lado direito: entrada degrau unitário
U = laplace(heaviside(t), t, s);  % Laplace{u(t)} = 1/s

% Equação na forma transformada:
% Y'' + 2Y' + Y → (s^2*Y - s*y(0) - y'(0)) + 2*(s*Y - y(0)) + Y
eq = (s^2*Y - s*y0 - dy0) + 2*(s*Y - y0) + Y == U;

% Resolver a equação para Y
Ysol = solve(eq, Y);

% Transformada inversa
yt = ilaplace(Ysol, s, t);

% Exibir resultado
disp('y(t) = ')
pretty(yt)

% Plotar no intervalo de 0 a 10
fplot(yt, [0 10])
grid on
xlabel('t'), ylabel('y(t)')
title('Solução y(t) da EDO via Transformada de Laplace')

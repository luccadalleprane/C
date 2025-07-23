clc
clear

% Definir função de transferência H(s)
num = [1 0 -1];             % s^2 - 1
den = [1 2 3 4];            % s^3 + 2s^2 + 3s + 4
H = tf(num, den);

% Definir vetor de tempo
t = linspace(0, 60, 1000);  % de 0 a 60 com 1000 pontos

% Definir entrada: x(t) = e^{-0.1t} * cos(t)
x = exp(-0.1*t) .* cos(t);

% Simular resposta do sistema
y = lsim(H, x, t);

% Plotar
plot(t, y, 'LineWidth', 2)
xlabel('t (s)')
ylabel('y(t)')
title('Resposta do Sistema à Entrada x(t) = e^{-0.1t} cos(t)')
grid on

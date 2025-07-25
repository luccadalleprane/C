%Questão B

clc;
clear;
close all;
% Tempo
t = 0:0.01:10;
dt = 0.01;
% Sinal de entrada: x(t) = u(t) - u(t-3) (pulso de 0 a 3)
x = double((t >= 0) & (t < 3));
% Resposta ao impulso do sistema S1: h1(t) = e^(-3t) * [u(t) - u(t-3)]
h1 = exp(-3*t) .* double((t >= 0) & (t < 3));
% Resposta ao impulso do sistema S2: h2(t) = t * cos(2*pi*t) * [u(t) - u(t-3)]
h2 = t .* cos(2*pi*t) .* double((t >= 0) & (t < 3));
% Convoluções das entradas com cada sistema
y1 = conv(x, h1) * dt;
y2 = conv(x, h2) * dt;
% Vetor de tempo ajustado para as convoluções
t_conv = 0:dt:(length(y1)-1)*dt;
% Saída total do sistema em paralelo
y = y1 + y2;
% Plot do resultado
figure;
plot(t_conv, y, 'k', 'LineWidth', 2);
xlabel('Tempo [s]');
ylabel('y(t)');
title('Resposta do Sistema em Paralelo - y(t)');
grid on;
xlim([0 10]);
ylim auto;

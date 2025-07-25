%Questão A

clc;
clear;
close all;
% Tempo
t = 0:0.01:10;
dt = 0.01;
% Sinal de entrada x(t) = u(t) - u(t-3)
x = double(t >= 0 & t < 3);
% Resposta ao impulso do sistema S1
h1 = exp(-3*t) .* (t >= 0 & t < 3);
% Resposta ao impulso do sistema S2
h2 = t .* cos(2*pi*t) .* (t >= 0 & t < 3);
% Primeira convolução: x(t) * h1(t)
y1 = conv(x, h1) * dt;
t1 = 0:dt:2*max(t);
% Segunda convolução: y1(t) * h2(t)
y = conv(y1, h2) * dt;
t2 = 0:dt:(length(y)-1)*dt;
% Plot do resultado
figure;
plot(t2, y, 'LineWidth', 2);
xlabel('Tempo [s]');
ylabel('y(t)');
title('Resposta y(t) para S1 e S2 em série');
grid on;
xlim([0 10]);


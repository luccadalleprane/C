clc
clear

% Criar sistema 2s^2 + 0s + 1 e s^3 + 3s^2 + 2s + 1
H = tf([2 0 1], [1 3 2 1]);

% Plotar o plano-s (polos e zeros)
pzmap(H)
grid on
title('Plano-s (Polos e Zeros) de H(s)')
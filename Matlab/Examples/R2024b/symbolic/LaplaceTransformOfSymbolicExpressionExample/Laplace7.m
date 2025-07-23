clc
clear

% Definindo as funções de transferência com tf()
s = tf('s');
H1 = s / (s + 4);
H2 = s / (s^2 + 4);
H3 = s^2 / (s^2 + 4);

% Soma dos blocos em paralelo: H1 + H2
H12 = parallel(H1, H2);

% Série com H3: H3 * (H1 + H2)
H_total = series(H3, H12);

% Exibir resultado
disp('Função de Transferência Total: ')
H_total

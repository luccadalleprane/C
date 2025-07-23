% Coeficientes do numerador (z^3 - 0.5z + 0.5)
num = [1 0 -0.5 0.5];

% Coeficientes do denominador (z^4 - 0.5z^3 - 0.5z^2 - 0.6z + 0.6)
den = [1 -0.5 -0.5 -0.6 0.6];

% Plotar zeros e polos no plano z
zplane(num, den)

% Adicionar rótulos
title('Plano z: Zeros e Polos de H(z)')
xlabel('Parte Real')
ylabel('Parte Imaginária')
grid on
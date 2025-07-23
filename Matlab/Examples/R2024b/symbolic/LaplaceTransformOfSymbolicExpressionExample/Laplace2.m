
% Define os coeficientes do numerador e denominador
b = [0 3 2 1]; % Numerador 3s^2 + 2s + 1
a = [1 0 1 0]; % Denominador s^3 + s

% Calcula frações parciais
[r,p,k] = residue(b,a)

% Exibir resultados
disp('Resíduos (r):');
disp(r);
disp('Polos (p):');
disp(p);
disp('Parte polinomial (k):');
disp(k);
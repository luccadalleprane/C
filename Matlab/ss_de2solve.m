% Questão 1 - Letra B

% Função para resolver uma equação diferencial em tempo discreto (diferença de segunda ordem)
% y[n+2] + a1*y[n+1] + a0*y[n] = 0
% com condições iniciais: y[0] = p1, y[1] = p2

function y = ss_de2solve(a1, a0, p1, p2, n)
   % ---- 1. Calcula raízes da equação característica ----
   % A equação característica associada é: z^2 + a1*z + a0 = 0
   coef = [1, a1, a0];          % Coeficientes do polinômio
   raizes = roots(coef);        % Calcula as raízes (soluções da equação característica)
   z1 = raizes(1);              % Primeira raiz
   z2 = raizes(2);              % Segunda raiz

   % ---- 2. Classificação do tipo de solução conforme as raízes ----
   if isreal(z1) && abs(z1 - z2) > 1e-8
       % Caso 1: raízes reais e distintas
       % Solução geral: y[n] = C1*z1^n + C2*z2^n
       C1 = (p2 * z2 - p1) / (z2 - z1);    % Determina C1 a partir das condições iniciais
       C2 = p1 - C1 * z1;                 
       y = C1 * z1.^n + C2 * z2.^n;       % Calcula a resposta

   elseif isreal(z1) && abs(z1 - z2) <= 1e-8
       % Caso 2: raízes reais e iguais
       % Solução geral: y[n] = (C1 + C2*n)*z1^n
       C1 = p1;
       C2 = (p2 - p1 * z1) / z1^2;
       y = (C1 + C2 .* n) .* z1.^n;

   else
       % Caso 3: raízes complexas conjugadas
       % z1 = r*e^(j*theta), z2 = r*e^(-j*theta)
       r = abs(z1);                     % Módulo das raízes
       theta = angle(z1);               % Argumento das raízes (frequência angular)

       % Sistema de equações para encontrar C1 e C2 usando as condições iniciais
       % A matriz A representa o sistema linear obtido substituindo n = 1 e n = 2 na solução geral
       A = [r^(-2) * cos(-2 * theta), r^(-2) * sin(-2 * theta);
            r^(-1) * cos(-1 * theta), r^(-1) * sin(-1 * theta)];
       b = [p2; p1];                    % Vetor das condições iniciais
       C = A \ b;                       % Resolve o sistema linear: A * [C1; C2] = b
       C1 = C(1);
       C2 = C(2);

       % Solução geral: y[n] = r^n * (C1*cos(n*theta) + C2*sin(n*theta))
       y = r.^n .* (C1 * cos(n * theta) + C2 * sin(n * theta));
   end
end


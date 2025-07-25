% Letra B
function y = ss_diff2solve(a1, a0, p1, p2, t)
    % Cria o polinômio característico da EDO: s^2 + a1*s + a0
    coeficiente = [1, a1, a0];
    
    % Calcula as raízes da equação característica
    raizes = roots(coeficiente);
    s1 = raizes(1);
    s2 = raizes(2);
    
    % Caso 1: raízes reais e distintas
    if isreal(s1) && s1 ~= s2
        % Calcula constantes C1 e C2 usando as condições iniciais
        C1 = (p2 - s2*p1) / (s1 - s2);
        C2 = p1 - C1;
        % Solução geral: y(t) = C1*e^(s1*t) + C2*e^(s2*t)
        y = C1*exp(s1*t) + C2*exp(s2*t);
        
    % Caso 2: raízes reais e iguais
    elseif isreal(s1) && s1 == s2
        % Calcula constantes C1 e C2 usando as condições iniciais
        C1 = p1;
        C2 = p2 - s1*p1;
        % Solução geral: y(t) = (C1 + C2*t)*e^(s1*t)
        y = (C1 + C2*t) .* exp(s1*t);
        
    % Caso 3: raízes complexas conjugadas
    else
        % Separa parte real e imaginária da raiz
        alpha = real(s1);
        beta = imag(s1);
        % Calcula constantes C1 e C2 usando as condições iniciais
        C1 = p1;
        C2 = (p2 - alpha*p1) / beta;
        % Solução geral: y(t) = e^(alpha*t) * (C1*cos(beta*t) + C2*sin(beta*t))
        y = exp(alpha*t) .* (C1*cos(beta*t) + C2*sin(beta*t));
    end
end

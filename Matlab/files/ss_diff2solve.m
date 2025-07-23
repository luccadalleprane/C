close all
clc
clear all 

function y = ss_diff2solve(a1, a0, p1, p2, t)

    % Coeficientes do polinômio característico
    coeficiente = [1, a1, a0];
    raizes = roots(coeficiente);  % Raízes s1 e s2

    s1 = raizes(1);
    s2 = raizes(2);

    if isreal(s1) && s1 ~= s2
        % Raízes reais e distintas
        C1 = (p2 - s2*p1) / (s1 - s2);
        C2 = p1 - C1;
        y = C1*exp(s1*t) + C2*exp(s2*t);
        
    elseif isreal(s1) && s1 == s2
        % Raízes reais e iguais
        % y(t) = (A + B*t)*exp(s1*t)
        C1 = p1;
        C2 = p2 - s1*p1;
        y = (C1 + C2*t) .* exp(s1*t);
        
    else
        % Raízes complexas conjugadas: s = α ± jβ
        alpha = real(s1);
        beta = imag(s1);
        % y(t) = e^(αt) * (A*cos(βt) + B*sin(βt))
        C1 = p1;
        C2 = (p2 - alpha*p1) / beta;
        y = exp(alpha*t) .* (C1*cos(beta*t) + C2*sin(beta*t));
    end
end
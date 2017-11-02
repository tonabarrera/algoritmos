x = round(linspace(0, 992, 100)); % Rango de graficacion
%logaritmo = log(x);
%lineal = x;
%nlogn = x.*log(x);
%cuadratica = x.^2;
%cubica = x.^3;
exponencial = 2.^x;
fact = factorial(x);
plot(x, ones(size(x))*1);

% Iniciar una vista de graficacion
figure;
%plot(vector_x, vector_y)
plot(x, logaritmo);
hold; % Para graficar mas de una funcion

plot(x, lineal);
plot(x, nlogn);
plot(x, cuadratica);
plot(x, cubica);
plot(x, exponencial);

plot(x, fact);
xlabel('n'); % Etiqueta del eje x
ylabel('f(n)'); % Etiqueta del eje y
legend('2^n', 'n!'); % Titulo de las graficas
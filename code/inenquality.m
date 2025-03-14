% 引入符号计算工具箱
syms n 

% 定义不等式
% 1.2-2
inequality = 8*n^2-64*n*log10(n);
% 1.2-3
% inequality = 100*n^2-2^n;

% 思考题1-1


% 求解不等式
solution = solve(inequality, n);

% 显示解
disp('解为：');
disp(solution);

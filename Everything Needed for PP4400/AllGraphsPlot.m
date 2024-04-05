% Assuming you have a table named 'results' with columns 'n', 'Empirical Run Time', 'Predicted Run Time'
% Replace 'results' with the actual name of your table

% Read data from the table
data = RandomizedSelectTable;

% Extract columns from the table
n_values = data.n;
empirical_run_time = data{:, 'EmpiricalRunTime'};
predicted_run_time = data{:, 'PredictedRunTime'};

% Plot data
figure;
plot(n_values, empirical_run_time, '-o', 'DisplayName', 'Empirical Run Time');
hold on;
plot(n_values, predicted_run_time, '-o', 'DisplayName', 'Predicted Run Time');

% Customize plot
title('Empirical vs Predicted Run Time Randomized Select Sort');
xlabel('n Iterations');
ylabel('Run Time (seconds)');
legend('Location', 'Best');
grid on;


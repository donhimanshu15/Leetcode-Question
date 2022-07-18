CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
Set N=N-1;
  RETURN (
SELECT DISTINCT(salary) from Employee order by salary DESC
      LIMIT 1 OFFSET N

      
  );
END
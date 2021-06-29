# Write a SQL query for a report that provides the following information
# for each person in the Person table, regardless if there is an address 
# for each of those people.
select P.FirstName, P.LastName, A.City, A.State from Person P
left join Address A
on P.PersonId = A.PersonId
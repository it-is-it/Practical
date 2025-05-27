using Microsoft.Data.Sqlite;
using System;

public class Student
{
    public int Id { get; set; }
    public string Name { get; set; }
}

class Program
{
    static string connectionString = "Data Source=student.db"; // SQLite DB file

    static void Main(string[] args)
    {
        Console.WriteLine("Student CRUD Operations with SQLite");

        // Create database and table
        CreateDatabase();

        // Insert a new student
        InsertStudent("John Doe");

        // Read students
        ReadStudents();

        // Update a student
        UpdateStudent(1, "Jane Doe");

        // Delete a student
        DeleteStudent(1);

        // Read students after delete
        ReadStudents();
    }

    static void CreateDatabase()
    {
        using (var connection = new SqliteConnection(connectionString))
        {
            connection.Open();

            var command = connection.CreateCommand();
            command.CommandText = @"
                CREATE TABLE IF NOT EXISTS Students (
                    Id INTEGER PRIMARY KEY AUTOINCREMENT,
                    Name TEXT NOT NULL
                );
            ";
            command.ExecuteNonQuery();
        }
    }

    static void InsertStudent(string name)
    {
        using (var connection = new SqliteConnection(connectionString))
        {
            connection.Open();
            
            var command = connection.CreateCommand();
            command.CommandText = @"
                INSERT INTO Students (Name)
                VALUES ($name);
            ";
            command.Parameters.AddWithValue("$name", name);
            command.ExecuteNonQuery();
        }
    }

    static void ReadStudents()
    {
        using (var connection = new SqliteConnection(connectionString))
        {
            connection.Open();

            var command = connection.CreateCommand();
            command.CommandText = "SELECT * FROM Students;";

            using (var reader = command.ExecuteReader())
            {
                while (reader.Read())
                {
                    Console.WriteLine($"ID: {reader.GetInt32(0)}, Name: {reader.GetString(1)}");
                }
            }
        }
    }

    static void UpdateStudent(int id, string newName)
    {
        using (var connection = new SqliteConnection(connectionString))
        {
            connection.Open();

            var command = connection.CreateCommand();
            command.CommandText = @"
                UPDATE Students
                SET Name = $newName
                WHERE Id = $id;
            ";
            command.Parameters.AddWithValue("$newName", newName);
            command.Parameters.AddWithValue("$id", id);
            command.ExecuteNonQuery();
        }
    }

    static void DeleteStudent(int id)
    {
        using (var connection = new SqliteConnection(connectionString))
        {
            connection.Open();

            var command = connection.CreateCommand();
            command.CommandText = @"
                DELETE FROM Students
                WHERE Id = $id;
            ";
            command.Parameters.AddWithValue("$id", id);
            command.ExecuteNonQuery();
        }
    }
}

<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "crud";  // Update to the correct database name

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}


$message = "";

// Create operation
if (isset($_POST['create'])) {
    $username = $_POST['username'];
    $email = $_POST['email'];

    $sql = "INSERT INTO users (username, email) VALUES ('$username', '$email')";
    if ($conn->query($sql) === TRUE) {
        $message = "New user created successfully";
    } else {
        $message = "Error: " . $sql . "<br>" . $conn->error;
    }
}

// Update operation
if (isset($_POST['update'])) {
    $id = $_POST['id'];
    $username = $_POST['username'];
    $email = $_POST['email'];

    $sql = "UPDATE users SET username='$username', email='$email' WHERE id=$id";
    if ($conn->query($sql) === TRUE) {
        $message = "User updated successfully";
    } else {
        $message = "Error updating user: " . $conn->error;
    }
}

// Delete operation

if (isset($_POST['delete'])) {
    $id = $_POST['id'];

    $sql = "DELETE FROM users WHERE id=$id";
    if ($conn->query($sql) === TRUE) {
        $message = "User deleted successfully";

        // Check if the table is now empty
        $checkEmpty = "SELECT COUNT(*) AS count FROM users";
        $result = $conn->query($checkEmpty);
        $row = $result->fetch_assoc();

        if ($row['count'] == 0) {
            // Reset auto-increment if table is empty
            $conn->query("ALTER TABLE users AUTO_INCREMENT = 1");
        }
    } else {
        $message = "Error deleting user: " . $conn->error;
    }
}

// Retrieve records (Read operation)
$users = [];
$sql = "SELECT * FROM users";
$result = $conn->query($sql);
if ($result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        $users[] = $row;
    }
}
?>

<?php
// Pre-fill form for editing
if (isset($_POST['edit'])) {
    $id = $_POST['id'];
    $username = $_POST['username'];
    $email = $_POST['email'];
}
?>
using Microsoft.AspNetCore.Mvc;
using StudentMVC.Models;
using System;

namespace StudentMVC.Controllers
{
    public class StudentController : Controller
    {
        public IActionResult Index()
        {
            int rollNo = 41; 
            int tableNumber = rollNo + 1;
            ViewBag.CurrentDateTime = DateTime.Now;
            ViewBag.Name = "Ishwor Timalsina";
            ViewBag.RollNo = rollNo;
            ViewBag.TableNumber = tableNumber;
            return View();
        }

        public IActionResult Create()
        {
            return View();
        }

        [HttpPost]
        public IActionResult Create(Student student)
        {
            if (ModelState.IsValid)
            {
                return RedirectToAction("Details", student);
            }
            return View(student);
        }

        public IActionResult Details(Student student)
        {
            return View(student);
        }
    }
}

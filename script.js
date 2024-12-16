document.addEventListener('DOMContentLoaded', () => {
    const boxes = document.querySelectorAll('.box');

    // Fade-in effect for boxes
    boxes.forEach((box, index) => {
        setTimeout(() => {
            box.classList.add('show');
        }, index * 300); // 300ms delay for each box
    });

    const contactForm = document.getElementById("contactForm");
    if (contactForm) {
        contactForm.addEventListener("submit", function (event) {
            event.preventDefault(); // Prevent the default form submission behavior

            // Fetch the user's message
            const message = document.getElementById("question").value;

            // Provide feedback for submission
            alert("Thank you for your message! We'll get back to you soon.");

            // Clear the form
            document.getElementById("question").value = "";

            // Close the modal
            document.getElementById("contactModal").style.display = "none";
        });
    } else {
        console.error("Contact form not found in the DOM.");
    }
});

// Contact Modal Functionality
const modal = document.getElementById("contactModal");
const openModalButton = document.getElementById("openModal");
const closeModalButton = document.querySelector(".close");

// Open modal
openModalButton.onclick = () => {
    modal.style.display = "block";
};

// modal questions
document.getElementById("contactForm").addEventListener("submit", function (event) {
    event.preventDefault(); // Prevent the default form submission behavior

    // Fetch the user's message
    const message = document.getElementById("question").value;

    // Simple feedback for submission (You can replace this with actual backend handling)
    alert("Thank you for your message! We'll get back to you soon.");

    // Clear the form
    document.getElementById("question").value = "";

    // Close the modal
    document.getElementById("contactModal").style.display = "none";
});

// Close modal
closeModalButton.onclick = () => {
    modal.style.display = "none";
};

// Close modal when clicking outside of it
window.onclick = (event) => {
    if (event.target === modal) {
        modal.style.display = "none";
    }
};

// Project video carousel
document.addEventListener("DOMContentLoaded", () => {
    const carouselVideos = document.querySelector(".carousel-videos");
    const videos = document.querySelectorAll(".carousel-videos video");
    const prevButton = document.getElementById("prev");
    const nextButton = document.getElementById("next");

    let currentIndex = 0;

    // Function to update carousel position
    function updateCarousel() {
        const offset = -currentIndex * 55; // Calculate offset percentage
        carouselVideos.style.transform = `translateX(${offset}%)`;
    }

    // Next button click
    nextButton.addEventListener("click", () => {
        currentIndex = (currentIndex + 1) % videos.length; // Loop back to the start
        updateCarousel();
    });

    // Previous button click
    prevButton.addEventListener("click", () => {
        currentIndex = (currentIndex - 1 + videos.length) % videos.length; // Loop to the end
        updateCarousel();
    });

    // Initialize carousel position
    updateCarousel();
});

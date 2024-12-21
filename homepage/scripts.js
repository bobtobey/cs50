// Universal Event Listener
document.addEventListener('DOMContentLoaded', function() {
    // initialize varibles for dialog and dialog buttons
    const toggleButton = document.querySelector("#open-article-image-bloc1");
    const dialogBloc = document.querySelector("#article-image-bloc1");
    const closeButton = document.querySelector("#article-image-bloc1 .btn-primary");

    // Toggle Dialog Display
    function dialogToggle() {
        if (dialogBloc.style.display === "none" || dialogBloc.style.display === "") {
            dialogBloc.style.display = "block";
        } else {
            dialogBloc.style.display = "none";
        }
    }

    // Set event listener for toggle button
    toggleButton.addEventListener("click", dialogToggle);

    // Set event listener for close button
    closeButton.addEventListener("click", dialogToggle);
});
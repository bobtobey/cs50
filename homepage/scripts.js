
// Initialize Dialogs on the page
function dialogInitializer(event) {

    // Confirm closest element has the data-dialog-target attribute
    const targetElement = event.target.closest('[data-dialog-target]');

    // approach 2
    if (!targetElement) {
        console.error('No target element with data-dialog-target attribute found.');
        return;
    }
    // Get dialog target id
    const dialogTarget = targetElement.getAttribute('data-dialog-target');
    if (!dialogTarget) {
        console.error('No dialog ID specified.');
        // console.log(dialogTarget);
        return;
    }
    // Set dialog element
    const dialog = document.querySelector(`[data-id="${dialogTarget}"]`);
    if (!dialog) {
        // console.error('Dialog element not found.');
        // console.log(dialog);
        return;
    }

    // Call Dialog functions
    dialogToggle(dialog, targetElement);
    // Check Dialog Display State
    const dialogState = dialog.getAttribute('data-dialog-state');
}

// Toggle Dialog Display
function dialogToggle(dialog, dialogCaller) {
    // Get current display state
    const currentState = window.getComputedStyle(dialog).display;

    if (currentState === 'none') {
        // Store the original border color if not already stored
        if (!dialog.dataset.originalBorderColor) {
            dialog.dataset.originalBorderColor = window.getComputedStyle(dialog).borderColor;
        }

        dialog.style.display = 'block';
        dialog.setAttribute('data-dialog-state', 'true');
        dialogCaller.classList.remove('btn-target-off');
        dialogCaller.classList.add('btn-target-on');
    } else {
        dialog.style.display = 'none';
        dialog.setAttribute('data-dialog-state', 'false');
        dialog.style.borderColor = dialog.dataset.originalBorderColor; // Reset to original border color when closing
        dialogCaller.classList.remove('btn-target-on');
        dialogCaller.classList.add('btn-target-off');
    }
}
// Universal Event Listener
document.addEventListener('DOMContentLoaded', function() {
    // Document listeners
    document.body.addEventListener('click', function(event) {
        const evntTarget= event.target;
        // console.log("Clicked element:", evntTarget);

        if(evntTarget.closest('[data-dialog-toggle="true"]')) {
            event.preventDefault();
            dialogInitializer(event, {
                alert: false,
                update: false
            });
        };

        // Close dialog with button
        if(evntTarget.closest('.btn-close')) {
            const btnClose = evntTarget.closest('.portfolio-assets-bloc');
            if(btnClose) {
                dialogToggle(btnClose);
            }
        }
    })
});

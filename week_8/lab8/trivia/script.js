// Change the color of a button clicked base  on whether or not the button containts the correct answer
function checkAnswer(user_answer) {
	const correctAnswers = ["Python","TCP"];
	return correctAnswers.includes(user_answer);

}
function answerButtonColor(button){

	if (checkAnswer(button.id)) {
		button.style.backgroundColor = 'green';
	}
	else {
		button.style.backgroundColor = 'red';
	}
}
function multipleChoiceResult() {
	let choiceButtons = document.querySelectorAll('.multiple_choice')
	choiceButtons.forEach(function (button) {
		button.onclick = () => answerButtonColor(button);
	})
}
document.addEventListener('DOMContentLoaded', function () {
	multipleChoiceResult();
	document.querySelector('form').addEventListener('submit', function (event) {
		let userAnswer = document.querySelector('#user_answer').value;
		alert("answer is:" + checkAnswer(userAnswer));
		event.preventDefault();
	})


})
